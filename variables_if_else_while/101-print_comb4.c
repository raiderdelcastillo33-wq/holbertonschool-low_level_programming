#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int first;
	int second;
	int third;

	first = 0;
	while (first <= 7)
	{
		second = first + 1;
		while (second <= 8)
		{
			third = second + 1;
			while (third <= 9)
			{
				putchar(first + '0');
				putchar(second + '0');
				putchar(third + '0');

				if (first != 7 || second != 8 || third != 9)
				{
					putchar(',');
					putchar(' ');
				}

				third++;
			}
			second++;
		}
		first++;
	}

	putchar('\n');

	return (0);
}
