#include "main.h"

/**
 * print_diagonal - Prints a diagonal line using backslashes
 * @n: Number of backslashes to print
 *
 * Return: Nothing
 */
void print_diagonal(int n)
{
	int i;
	int spaces;

	for (i = 0; i < n; i++)
	{
		for (spaces = 0; spaces < i; spaces++)
		{
			_putchar( );
		}
		_putchar(\);
		_putchar(n);
	}
	if (n <= 0)
	{
		_putchar(n);
	}
}
