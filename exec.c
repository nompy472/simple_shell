#include "shell.h"

/**
 * execution - executes command
 * @cp: command to execute
 * @cmd: pointers to commands
 * Return: 0
 */

void execution(char *cp, char **cmd)
{
	char **env = environ;
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
