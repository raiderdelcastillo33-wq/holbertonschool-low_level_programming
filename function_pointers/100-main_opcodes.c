#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 for invalid argc, 2 for negative bytes
 */
int main(int argc, char *argv[])
{
	int bytes;
	int i;
	unsigned char *main_address;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	main_address = (unsigned char *)main;

	i = 0;
	while (i < bytes)
	{
		printf("%02x", main_address[i]);

		if (i < bytes - 1)
			printf(" ");

		i++;
	}

	printf("\n");

	return (0);
}
