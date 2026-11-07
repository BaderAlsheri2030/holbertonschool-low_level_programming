#include <stdio.h>

/**
 * main - Prints the lowercase alphabet followed by a newline
 *
 * Return: Always 0
 */
int main(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');

	return (0);
}
