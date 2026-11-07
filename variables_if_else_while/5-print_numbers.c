#include <stdio.h>

/**
 * main - Prints single-digit base 10 numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int digit;

	digit = 0;
	while (digit <= 9)
	{
		putchar(digit + 0);
		digit++;
	}
	putchar('\n');

	return (0);
}
