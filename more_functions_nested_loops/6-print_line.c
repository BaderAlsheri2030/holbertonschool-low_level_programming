#include "main.h"

/**
 * print_line - Prints a straight line of underscores
 * @n: Number of underscores to print
 *
 * Return: Nothing
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar(_);
	}
	_putchar(n);
}
