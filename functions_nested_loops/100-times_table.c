#include "main.h"

/**
 * print_num - prints a number with the correct spacing
 * @num: number to print
 */
void print_num(int num)
{
	if (num < 10)
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(num + '0');
	}
	else if (num < 100)
	{
		_putchar(' ');
		_putchar((num / 10) + '0');
		_putchar((num % 10) + '0');
	}
	else
	{
		_putchar((num / 100) + '0');
		_putchar(((num / 10) % 10) + '0');
		_putchar((num % 10) + '0');
	}
}

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number of the times table
 */
void print_times_table(int n)
{
	int row;
	int col;
	int result;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		_putchar('0');

		for (col = 1; col <= n; col++)
		{
			result = row * col;
			_putchar(',');
			_putchar(' ');
			print_num(result);
		}

		_putchar('\n');
	}
}
