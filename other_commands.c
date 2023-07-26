#include "main.h"
/**
 * exit_function - Function to execute the "exit" command
 * @argc: num of exit arguments
 * @arguments: array of command arguments
 */
void exit_function(int argc, char *arguments[])
{
	int exit_status;

	if (argc == 2)
	{
		exit_status = atoi(arguments[1]);
		exit(exit_status);
	}
	else
	{
		exit(0);
	}
}

/**
 * cd_function - Function to execute the "cd" command
 * @argc: num of argument
 * @arguments: arguments
 */
void cd_function(int argc, char *arguments[])
{
	if (argc == 1)
	{
		chdir(getenv("HOME"));
	}
	else if (argc == 2)
	{
		if (chdir(arguments[1]) != 0)
		{
			perror("cd");
		}
	}
	else
	{
		printf("cd: Too many arguments.\n");
	}
}
