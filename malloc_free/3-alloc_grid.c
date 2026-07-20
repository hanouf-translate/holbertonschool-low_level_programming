#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Returns a pointer to a 2-dimensional array of integers
 *              with each element initialized to 0.
 * @width: The width of the grid (columns).
 * @height: The height of the grid (rows).
 *
 * Return: A pointer to the 2D array of integers,
 *         or NULL if width/height is 0 or negative, or on allocation failure.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for the array of row pointers */
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	/* Allocate memory for each individual row */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* Clean up previously allocated memory on failure */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* Initialize elements to 0 */
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
