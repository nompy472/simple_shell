#include "shell.h"

/**
 * find_path - finds the path
 * Return: NULL or path
 */

char *find_path(void)
{
	char **env = environ, *path = NULL;
	int x = 0;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

/**
 * append_path - adds path to command
 * @path: path of command
 * @command: entered command
 * Return: command with path
 */

char *append_path(char *path, char *command)
{
	size_t i = 0, j = 0;
	char *buf;

	if (command == 0)
		command = "";
	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buf)
		return (NULL);
	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}
	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (command[j])
	{
		buf[i + j] = command[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

/**
 * test_path - checks whether path is valid
 * @path: path from tokens
 * @command: command input
 * Return: path or NULL
 */

char *test_path(char **path, char *command)
{
	char *output;
	int i = 0;

	while (path[i])
	{
		output = append_path(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
