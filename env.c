#include "shell.h"

/**
 * print_env -prints the environment to standard output
 * Return: 0
 */

void print_env(void)
{
	char **env = environ;
	int x = 0;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
