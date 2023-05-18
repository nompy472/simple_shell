#include "shell.h"

/**
 *  _strcmp - comparison between two strings
 *  @s1: first string
 *  @s2: second string
 *  Return: returns difference
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;
	output = (*(s1 + i) - *(s2 + i));
	return (output);
}

/**
 * _strchr - searching for a character in a string
 * @s: string to be evaluated
 * @c: searched character
 * Return: pointer
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

/**
 * _strdup - duplicates a string
 * @s: string to copy
 * Return: a pointer
 */

char *_strdup(char *s)
{
	int i, len;
	char *ptr;

	if (s == NULL)
		return (NULL);
	len = _strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));

	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];
	ptr[i++] = '\0';
	return (ptr);
}

/**
 * _strncmp - comparing string bytes
 * @s1: first string
 * @s2: second string
 * @n: no. of bytes
 * Return: the difference
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strlen - print string length
 * @s: checked string
 * Return: length count
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
