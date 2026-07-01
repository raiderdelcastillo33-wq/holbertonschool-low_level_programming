#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: String to check.
 * @accept: String containing accepted bytes.
 *
 * Return: Number of bytes in the initial segment of s found in accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count, found;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		j = 0;
		found = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				found = 1;
			j++;
		}
		if (found == 0)
			return (count);
		count++;
		i++;
	}

	return (count);
}
