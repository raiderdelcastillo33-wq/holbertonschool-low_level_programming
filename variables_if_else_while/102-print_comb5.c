#include <stdio.h>

/**
 * main - prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int first;
	int second;

	first = 0;

	while (first <= 98)
	{
		second = first + 1;

		while (second <= 99)
		{
			putchar((first / 10) + '0');
			putchar((first % 10) + '0');
			putchar(' ');
			putchar((second / 10) + '0');
			putchar((second % 10) + '0');

			if (first != 98 || second != 99)
			{
				putchar(',');
				putchar(' ');
			}

			second++;
		}

		first++;
	}

	putchar('\n');

	return (0);
}
