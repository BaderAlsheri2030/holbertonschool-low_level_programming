#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to print
 *
 * Return: Nothing
 */
void print_number(int n)
{
	int divisor;
	int digit;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n < 0)
	{
		_putchar('-');
	}
	else
	{
		n = -n;
	}

	divisor = 1;
	while (n / divisor <= -10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		digit = n / divisor;
		_putchar('0' - digit);
		n %= divisor;
		divisor /= 10;
	}
}
