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

	if (command[strlen(command) - 1] == '\n')
		command[strlen(command) - 1] = '\0';

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
 * strtrim - trims the string
 * @str: string to trim
 */
void strtrim(char *str)
{
	int start = 0, end = strlen(str) - 1, i;

	while (isspace(str[start]))
		start++;

	while ((end >= start) && isspace(str[end]))
		end--;

	for (i = start; i <= end; i++)
		str[i - start] = str[i];

	str[end - start + 1] = '\0';
}

/**
 * main - entry point
 * Return: Always Success
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH], *arguments[MAX_ARGUMENTS];
	int argc;

	if (isatty(fileno(stdin)))
	{
		printf("$ ");
		fflush(stdout); }
	while (1)
	{
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			break; }

		strtrim(command);

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
		if (isatty(fileno(stdin)))
		{
			printf("$ ");
			fflush(stdout); } }
	return (0);
}
