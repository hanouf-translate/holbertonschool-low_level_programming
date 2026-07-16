#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers
 * @a: The array to reverse
 * @n: The number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int start = 0;
	int end = n - 1;
	int tmp = 0;

	for (start = 0; start < end; start++, end--)
	{
		tmp = a[start];
		a[start] = a[end];
		a[end] = tmp;
	}
}
