#include "shell.h"

/**
 * _putchar - prints to the standard output
 * @c: char to be printed
 * Return: 1(success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_s - prints a string to the standard output
 * @s: string to print out
 * Return: array of char
 */

int print_s(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
