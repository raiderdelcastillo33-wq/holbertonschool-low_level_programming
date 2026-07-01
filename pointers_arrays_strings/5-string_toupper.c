#include "main.h"

/**
 * string_toupper - Changes all lowercase letters to uppercase.
 * @str: String to convert.
 *
 * Return: Pointer to str.
 */
char *string_toupper(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}

	return (str);
}
