#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: number of bytes to print
 *
 * Return: Nothing
 */
void print_buffer(char *b, int size)
{
	int i, j, k;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			k = i + j;
			if (k < size)
				printf("%02x", (unsigned char)b[k]);
			else
				printf("  ");

			if (j % 2)
				printf(" ");
		}

		for (j = 0; j < 10 && i + j < size; j++)
		{
			k = i + j;
			if (b[k] >= 32 && b[k] <= 126)
				printf("%c", b[k]);
			else
				printf(".");
		}

		printf("\n");
	}
}
