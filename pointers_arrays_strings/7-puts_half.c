#include "main.h"

/**
 * puts_half - Prints the second half of a string.
 * @str: String to print.
 */
void puts_half(char *str)
{
	int len;
	int start;

	len = 0;
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}

	_putchar('\n');
}
