#include "main.h"

/**
 * array_range - Creates an array of integers containing values from min to max.
 * @min: The minimum (starting) value, included.
 * @max: The maximum (ending) value, included.
 *
 * Return: Pointer to the newly created array.
 *         If min > max or malloc fails, returns NULL.
 */
int *array_range(int min, int max)
{
	int *arr;
	int size, i;

	/* Edge case: min cannot be strictly greater than max */
	if (min > max)
		return (NULL);

	/* Calculate total number of elements including both min and max */
	size = max - min + 1;

	/* Allocate memory for the integer array */
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	/* Populate array with sequential values from min to max */
	for (i = 0; i < size; i++)
	{
		arr[i] = min;
		min++;
	}

	return (arr);
}
