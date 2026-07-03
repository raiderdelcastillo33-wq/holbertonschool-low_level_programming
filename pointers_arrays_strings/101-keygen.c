#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a valid random password for 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum = 0;
	int random_char;
	int remaining;

	srand(time(NULL));

	while (sum < 2772)
	{
		remaining = 2772 - sum;
		random_char = (rand() % 94) + 33;

		if (remaining - random_char == 0 ||
		    remaining - random_char >= 33)
		{
			putchar(random_char);
			sum += random_char;
		}
	}

	putchar('\n');

	return (0);
}
