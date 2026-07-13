#include "main.h"

/**
 * sqrt_helper - Finds the natural square root of a number
 * @n: Number to check
 * @i: Current possible square root
 *
 * Return: Natural square root, or -1 if none exists
 */
int sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}

	if (i * i > n)
	{
		return (-1);
	}

	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: Number to calculate
 *
 * Return: Natural square root of n, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (sqrt_helper(n, 0));
}
