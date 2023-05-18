#include "shell.h"

/**
 * checker - checks for  built in function
 * @cmd: tokenized command
 * @buf: line
 * Return: 1 or 0
 */

int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}

/**
 * handle_builtin - handles execution of builtins
 * @command: tokenized commands
 * @line: input read from stdin
 * Return: 1 or 0
 */

int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	return (0);
}
