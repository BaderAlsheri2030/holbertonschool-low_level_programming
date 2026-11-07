#include <stdio.h>

/**
 * main - Prints lowercase alphabet except q and e
 *
 * Return: Always 0
 */
int main(void)
{
	char letter;

	letter = a;
	while (letter <= z)
	{
		if (letter != q && letter != e)
		{
			putchar(letter);
		}
		letter++;
	}
	putchar(n);

	return (0);
}
