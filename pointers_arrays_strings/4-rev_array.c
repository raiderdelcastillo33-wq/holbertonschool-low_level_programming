#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers.
 * @a: Array of integers.
 * @n: Number of elements in the array.
 */
void reverse_array(int *a, int n)
{
	int left;
	int right;
	int temp;

	left = 0;
	right = n - 1;

	while (left < right)
	{
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;
		left++;
		right--;
	}
}
