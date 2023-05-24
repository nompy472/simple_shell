#include "shell.h"

/**
 * prompt_user - request input from user
 * Return: void
 */

void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "cisfun$ ", 7);

}
