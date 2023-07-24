#include "main.h"

/**
 * setenv_function - Function to execute the "setenv" command
 * @argc: num of argument
 * @arguments: arguments
 */
void setenv_function(int argc, char *arguments[])
{
	if (argc != 3)
	{
		printf("setenv: Invalid number of arguments.Usage: setenv VARIABLE VALUE\n");
	}
	else
	{
		if (setenv(arguments[1], arguments[2], 1) != 0)
		{
			perror("setenv");
		}
	}
}

/**
 * unsetenv_function - Function to execute the "unsetenv" command
 * @argc: num of argument
 * @arguments: arguments
 */
void unsetenv_function(int argc, char *arguments[])
{
	if (argc != 2)
	{
		printf("unsetenv: Invalid number of arguments. Usage: unsetenv VARIABLE\n");
	}
	else
	{
		if (unsetenv(arguments[1]) != 0)
		{
			perror("unsetenv");
		}
	}
}
