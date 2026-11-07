#include "main.h"

/**
 * _isupper - Checks whether a character is uppercase
 * @c: The character to check
 *
 * Return: 1 if uppercase, otherwise 0
 */
	int _isupper(int c)
{
	/* TODO: Add a condition that checks whether c is from 'A' through 'Z'. */
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}

	return (0);
}
