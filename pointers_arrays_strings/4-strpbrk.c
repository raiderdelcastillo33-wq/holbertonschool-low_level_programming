#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: String to search in.
 * @accept: String containing bytes to match.
 *
 * Return: Pointer to the matching byte in s, or 0 if no match is found.
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (s + i);
			j++;
		}
		i++;
	}

	return (0);
}
