#include "main.h"

/**
 * _strstr - Locates a substring.
 * @haystack: String to search in.
 * @needle: Substring to locate.
 *
 * Return: Pointer to the beginning of needle, or 0 if not found.
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;

	if (needle[0] == '\0')
		return (haystack);

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;

		if (needle[j] == '\0')
			return (haystack + i);

		i++;
	}

	return (0);
}
