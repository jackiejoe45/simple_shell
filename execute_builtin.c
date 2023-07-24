
#include "main.h"
/**
 * execute_builtin - Function to execute external commands
 * @arguments: arguments
 */
void execute_builtin(char *arguments[])
{
	pid_t pid = fork();
	char *path;

	if (pid == 0)
	{
		execvp(arguments[0], arguments);
		path = getenv("PATH");

		if (path != NULL)
		{
			char full_path[MAX_COMMAND_LENGTH];
			char *dir = strtok(path, ":");

			while (dir != NULL)
			{
				snprintf(full_path, sizeof(full_path), "%s/%s", dir, arguments[0]);
				execv(full_path, arguments);
				dir = strtok(NULL, ":");
			}
		}
		perror(arguments[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
