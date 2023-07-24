#include "main.h"
/**
 * handle_args - handle arguments and tokenize the command
 * @command: command
 * @arguments : arguments
 * @argc: num of arguments
 */
void handle_args(char *command, char *arguments[], int *argc)
{
	char *token;

	*argc = 0;
	token = strtok(command, " ");

	while (token != NULL && *argc < MAX_ARGUMENTS - 1)
	{
		arguments[(*argc)++] = token;
		token = strtok(NULL, " ");
	}
	arguments[*argc] = NULL;
}


/**
 * main - entry point
 * Return: Always Success
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH], *arguments[MAX_ARGUMENTS];
	char *comment_pos;
	int argc;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break; }

		command[strcspn(command, "\n")] = '\0';
		comment_pos = strchr(command, '#');
		if (comment_pos != NULL)
		{
			*comment_pos = '\0'; }

		handle_args(command, arguments, &argc);
		if (argc > 0 && strcmp(arguments[0], "exit") == 0)
		{
			exit_function(argc, arguments); }
		else if (argc > 0 && strcmp(arguments[0], "cd") == 0)
		{
			cd_function(argc, arguments); }
		else if (argc > 0 && strcmp(arguments[0], "setenv") == 0)
		{
			setenv_function(argc, arguments); }
		else if (argc > 0 && strcmp(arguments[0], "unsetenv") == 0)
		{
			unsetenv_function(argc, arguments); }
		else
		{
			execute_builtin(arguments); }
	}
	return (0);
}
