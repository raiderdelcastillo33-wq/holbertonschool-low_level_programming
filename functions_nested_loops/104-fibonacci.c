#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, next;
	unsigned long f1_high, f1_low, f2_high, f2_low;
	unsigned long high, low, carry;
	int count;

	printf("%lu, %lu", f1, f2);

	for (count = 3; count <= 92; count++)
	{
		next = f1 + f2;
		printf(", %lu", next);
		f1 = f2;
		f2 = next;
	}

	f1_high = f1 / 10000000000;
	f1_low = f1 % 10000000000;
	f2_high = f2 / 10000000000;
	f2_low = f2 % 10000000000;

	for (; count <= 98; count++)
	{
		low = f1_low + f2_low;
		carry = low / 10000000000;
		low %= 10000000000;
		high = f1_high + f2_high + carry;

		printf(", %lu%010lu", high, low);

		f1_high = f2_high;
		f1_low = f2_low;
		f2_high = high;
		f2_low = low;
	}

	printf("\n");

	return (0);
}
