#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * is_comment - Check if the command is a comment
 * @command: command to check
 * Return: 1 if the command is a comment, 0 otherwise.
 */
int is_comment(const char *command)
{
	int i = 0;

	while (command[i] == ' ')
		i++;
	return (command[i] == '#');
}
