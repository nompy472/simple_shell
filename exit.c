#include "shell.h"

/**
* exit_cmd - handles the exit command
* @command: tokenized command
* @line: input line
*
* Return: nothing
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
