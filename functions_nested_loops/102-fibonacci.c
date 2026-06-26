#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long first;
	unsigned long second;
	unsigned long next;
	int count;

	first = 1;
	second = 2;

	for (count = 1; count <= 50; count++)
	{
		printf("%lu", first);

		if (count != 50)
			printf(", ");

		next = first + second;
		first = second;
		second = next;
	}

	printf("\n");

	return (0);
}
