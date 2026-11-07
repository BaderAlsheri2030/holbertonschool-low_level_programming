#include <stdio.h>

/**
 * main - Prints _putchar followed by a newline
 *
 * Return: Always 0
 */
int main(void)
{
	char text[] = "_putchar";
	int i;

	for (i = 0; text[i] != 0; i++)
	{
		putchar(text[i]);
	}
	putchar('\n');

	return (0);
}
