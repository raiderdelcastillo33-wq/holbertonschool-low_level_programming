#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: String to convert.
 *
 * Return: The integer converted from the string, or 0 if no number is found.
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;
	int found_digit;

	i = 0;
	sign = 1;
	result = 0;
	found_digit = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = sign * -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			result = result * 10 - (s[i] - '0');
		}
		else if (found_digit == 1)
		{
			break;
		}

		i++;
	}

	if (sign == 1)
		result = -result;

	return (result);
}
