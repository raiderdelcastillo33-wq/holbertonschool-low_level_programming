#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals.
 * @a: Pointer to the square matrix.
 * @size: Size of the square matrix.
 *
 * Return: Nothing.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1;
	int sum2;

	i = 0;
	sum1 = 0;
	sum2 = 0;
	while (i < size)
	{
		sum1 += a[(i * size) + i];
		sum2 += a[(i * size) + (size - 1 - i)];
		i++;
	}

	printf("%d, %d\n", sum1, sum2);
}
