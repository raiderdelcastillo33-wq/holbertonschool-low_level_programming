#include "main.h"

/**
 * reverse_string - reverses a string in place
 * @s: string to reverse
 * @len: string length
 *
 * Return: Nothing
 */
void reverse_string(char *s, int len)
{
	int start, end;
	char tmp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
}

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number
 * @n2: second number
 * @r: buffer to store the result
 * @size_r: size of the buffer
 *
 * Return: pointer to the result, or 0 if it cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, i, j, k, carry, sum;

	len1 = 0;
	len2 = 0;
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	i = len1 - 1;
	j = len2 - 1;
	k = 0;
	carry = 0;
	while (i >= 0 || j >= 0 || carry)
	{
		if (k >= size_r - 1)
			return (0);
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}
	r[k] = '\0';
	reverse_string(r, k);
	return (r);
}
