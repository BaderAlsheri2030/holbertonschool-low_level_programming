#include <stdio.h>

/**
 * main - Finds the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long n;
	unsigned long factor;
	unsigned long largest;

	n = 612852475143UL;
	largest = 0;

	while (n % 2 == 0)
	{
		largest = 2;
		n /= 2;
	}

	for (factor = 3; factor <= n / factor; factor += 2)
	{
		while (n % factor == 0)
		{
			largest = factor;
			n /= factor;
		}
	}

	if (n > 1)
	{
		largest = n;
	}

	printf("%lu\n", largest);
	return (0);
}
