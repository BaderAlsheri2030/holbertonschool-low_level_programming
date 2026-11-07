#include <stdio.h>

/**
 * main - Prints lowercase hexadecimal digits
 *
 * Return: Always 0
 */
int main(void)
{
	int digit;

	digit = 0;
	while (digit < 10)
	{
		putchar(digit + 0);
		digit++;
	}

	digit = 'a';
	while (digit <= 'f')
	{
		putchar(digit);
		digit++;
	}

	putchar('\n');
	return (0);
}
