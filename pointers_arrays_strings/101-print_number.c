#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: Nothing
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
	}
	else
	{
		n = -n;
	}

	if (n / 10)
	{
		print_number(-(n / 10));
	}

	_putchar('0' - (n % 10));
}
