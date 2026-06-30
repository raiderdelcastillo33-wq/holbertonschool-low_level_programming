#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: String to reverse.
 */
void rev_string(char *s)
{
	int len;
	int start;
	int end;
	char temp;

	len = 0;
	while (s[len] != '\0')
		len++;

	start = 0;
	end = len - 1;

	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}
