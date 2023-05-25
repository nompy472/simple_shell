#include "shell.h"

/**
 * bfree - frees a pointer
 * @ptr: pointer to free
 * Return: 0 (success) else 1
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (0);
	}
	return (1);
}
