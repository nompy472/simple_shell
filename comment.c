#include "shell.h"

/**
 * remove_comments - replaces first instance of '#' with NULL
 * @buf: address of string to modify
 * Return: 0
 */

void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
