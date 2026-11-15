#include <limits.h>
#include "main.h"

/**
 * append_digit - appends a digit while checking integer limits
 * @result: number built so far
 * @digit: next digit to append
 * @negative: whether the number is negative
 *
 * Return: updated number, clamped to the int range if necessary
 */
static int append_digit(int result, int digit, int negative)
{
	if (negative)
	{
		if (result < INT_MIN / 10 ||
		    (result == INT_MIN / 10 && -digit < INT_MIN % 10))
			return (INT_MIN);
		return (result * 10 - digit);
	}

	if (result > INT_MAX / 10 ||
	    (result == INT_MAX / 10 && digit > INT_MAX % 10))
		return (INT_MAX);
	return (result * 10 + digit);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted number, or 0 if there are no digits
 */
int _atoi(char *s)
{
	int i;
	int result;
	int negative;
	int started;

	i = 0;
	result = 0;
	negative = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = append_digit(result, s[i] - '0', negative);
		}
		else if (started)
			break;
		else if (s[i] == '-')
			negative = !negative;
		i++;
	}
	return (result);
}
