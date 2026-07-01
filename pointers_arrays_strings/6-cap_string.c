#include "main.h"

/**
 * is_separator - Checks if a character is a word separator.
 * @c: Character to check.
 *
 * Return: 1 if separator, 0 otherwise.
 */
int is_separator(char c)
{
	int i;
	char separators[] = " \t\n,;.!?\"(){}";

	i = 0;
	while (separators[i] != '\0')
	{
		if (c == separators[i])
			return (1);
		i++;
	}

	return (0);
}

/**
 * cap_string - Capitalizes all words of a string.
 * @str: String to capitalize.
 *
 * Return: Pointer to str.
 */
char *cap_string(char *str)
{
	int i;

	i = 0;

	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;

	while (str[i] != '\0')
	{
		if (is_separator(str[i]) && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - 32;
		i++;
	}

	return (str);
}
