#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_args(char *command, char *arguments[], int *argc);
void exit_function(int argc, char *arguments[]);
void cd_function(int argc, char *arguments[]);
void setenv_function(int argc, char *arguments[]);
void unsetenv_function(int argc, char *arguments[]);
void execute_builtin(char *arguments[]);

#endif /* SHELL_H */
