#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Returns the length of a string
 * @s: String to measure
 *
 * Return: Length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * string_nconcat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes from s2
 *
 * Return: Pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (n >= len2)
		n = len2;

	str = malloc(sizeof(char) * (len1 + n + 1));
	if (str == NULL)
		return (NULL);

	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < n)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';

	return (str);
}
