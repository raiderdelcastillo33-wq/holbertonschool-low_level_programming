#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times
 */
void print_alphabet_x10(void)
{
	int line;
	char c;

	line = 0;

	while (line < 10)
	{
		c = 'a';

		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}

		_putchar('\n');
		line++;
	}
}
