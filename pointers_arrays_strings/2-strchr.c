#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: String to search in.
 * @c: Character to locate.
 *
 * Return: Pointer to the first occurrence of c, or 0 if not found.
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}

	if (s[i] == c)
		return (s + i);

	return (0);
}
