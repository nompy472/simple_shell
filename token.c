#include "shell.h"

/**
 * tokenizer -creates tokens
 * @line: to be tokenized
 * Return: array of char
 */

char **tokenizer(char *line)
{
	int tokensize = 1;
	size_t index = 0, flag = 0;
	char **tokens = NULL;
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";

	buf = _strdup(line);

	if (!buf)
		return (NULL);
	bufp = buf;
	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}
