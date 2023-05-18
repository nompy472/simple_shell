#include "shell.h"

/**
 * free_buffers - frees a buffers
 * @buf: buffer to free
 * Return: void
 */

void free_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
