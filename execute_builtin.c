#include "main.h"

/**
 * remove_trailing_newline - remove the trailing newline character
 * @str: The string to modify
 */
void remove_trailing_newline(char *str)
{
	int length = strlen(str);

	if (length > 0 && str[length - 1] == '\n')
	{
		printf("Before removing newline: %s\n", str);
		str[length - 1] = '\0';
		printf("After removing newline: %s\n", str);
	}
}

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
				dir = strtok(NULL, ":"); }
		}
		perror(arguments[0]);
		exit(EXIT_FAILURE); }
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE); }
	else
	{
		int status;

		wait(&status);

		if (WIFEXITED(status))
		{
			int length = 0;

			while (arguments[length] != NULL)
				length++;
			if (length > 0 && WEXITSTATUS(status) == 0)
			{
				remove_trailing_newline(arguments[length - 1]); } } } }
