#include "shell.h"


/**
 *  _eputchar - writes char c to standard error
 *  @c: a char to print
 *  Return: 0(success) else 1
 */

int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (0);
}

/**
 * _putfd - writes the char c to file
 * @c: char to write
 * @fd: file to write on
 * Return: 0 success else 1
 */

int _putfd(char c, int fd)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (0);
}

/**
 * _eputs - prints an input string
 * @str: the string to be print
 * Return: void
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putsfd - writes an input string
 * @fd: the file to write on
 * @str: the string to print
 * Return: no. of chars
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
