#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int left;
	int right;
	char temp;

	left = 0;
	right = 0;

	while (s[right] != '\0')
		right++;

	right--;

	while (left < right)
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
}
