#include <stdio.h>

/**
 * main - prints the sum of the even-valued Fibonacci terms
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long first;
	unsigned long second;
	unsigned long next;
	unsigned long sum;

	first = 1;
	second = 2;
	sum = 0;

	while (second <= 4000000)
	{
		if (second % 2 == 0)
			sum += second;

		next = first + second;
		first = second;
		second = next;
	}

	printf("%lu\n", sum);

	return (0);
}
