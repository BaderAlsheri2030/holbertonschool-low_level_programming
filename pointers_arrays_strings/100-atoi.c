#include <limits.h>
#include "main.h"

/**
 * _atoi - converts the first number in a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if there are no digits
 */
int _atoi(char *s)
{
	int i;
	int result;
	int negative;
	int digit;
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
			digit = s[i] - '0';

			if (negative)
			{
				if (result < INT_MIN / 10 ||
				    (result == INT_MIN / 10 &&
				     -digit < INT_MIN % 10))
					return (INT_MIN);
				result = result * 10 - digit;
			}
			else
			{
				if (result > INT_MAX / 10 ||
				    (result == INT_MAX / 10 &&
				     digit > INT_MAX % 10))
					return (INT_MAX);
				result = result * 10 + digit;
			}
		}
		else if (started)
		{
			break;
		}
		else if (s[i] == '-')
		{
			negative = !negative;
		}
		i++;
	}

	return (result);
}
