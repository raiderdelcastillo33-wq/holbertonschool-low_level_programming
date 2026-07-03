#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of a number.
 *
 * Return: Always 0.
 */
int main(void)
{
	long int n = 612852475143;
	long int factor = 2;
	long int largest = 1;

	while (factor * factor <= n)
	{
		if (n % factor == 0)
		{
			largest = factor;
			n = n / factor;
		}
		else
		{
			factor++;
		}
	}

	if (n > 1)
		largest = n;

	printf("%ld\n", largest);

	return (0);
}
