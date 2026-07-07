#include <stdlib.h>
#include "main.h"

/**
 * print_error - Prints Error and exits with status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * digit_length - Checks if a string contains only digits and gets length
 * @s: String to check
 *
 * Return: Length if valid, 0 otherwise
 */
int digit_length(char *s)
{
	int i;

	if (s == NULL || s[0] == '\0')
		return (0);

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (i);
}

/**
 * print_result - Prints multiplication result
 * @result: Result array
 * @size: Size of result array
 */
void print_result(int *result, int size)
{
	int i;
	int started;

	i = 0;
	started = 0;
	while (i < size)
	{
		if (result[i] != 0)
			started = 1;
		if (started)
			_putchar(result[i] + '0');
		i++;
	}

	if (!started)
		_putchar('0');

	_putchar('\n');
}

/**
 * multiply - Multiplies two positive numbers as strings
 * @num1: First number
 * @num2: Second number
 * @result: Result array
 * @len1: Length of num1
 * @len2: Length of num2
 */
void multiply(char *num1, char *num2, int *result, int len1, int len2)
{
	int i;
	int j;
	int mul;
	int sum;

	i = len1 - 1;
	while (i >= 0)
	{
		j = len2 - 1;
		while (j >= 0)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
			j--;
		}
		i--;
	}
}

/**
 * main - Multiplies two positive numbers
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int len1;
	int len2;
	int size;
	int *result;
	int i;

	if (argc != 3)
		print_error();

	len1 = digit_length(argv[1]);
	len2 = digit_length(argv[2]);
	if (len1 == 0 || len2 == 0)
		print_error();

	size = len1 + len2;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		print_error();

	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}

	multiply(argv[1], argv[2], result, len1, len2);
	print_result(result, size);

	free(result);

	return (0);
}
