#include "shell.h"

/**
 * exit_cmd - exits the shell
 * @command: arguments array
 * @line: input line
 */

char *line = "exit";
char *command[] = {"exit", NULL};

int exit_cmd(char **command, char *line)
{
	if (command[0] != NULL && _strcmp(command[0], "exit") == 0)
	{
		exit(0);
	}
	return (*line);

}
