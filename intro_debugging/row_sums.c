#include <stdio.h>

/**
 * row_sum - Computes the sum of a specific row's matrix elements
 * @row: The current row number
 * @cols: Total number of columns
 *
 * Return: Sum of the row
 */
int row_sum(int row, int cols)
{
	int c;
	int sum = 0;

	for (c = 1; c <= cols; c++)
	{
		sum += row * c;
	}

	return (sum);
}

/**
 * total_sum - Computes the total sum of all rows combined
 * @rows: Total number of rows
 * @cols: Total number of columns
 *
 * Return: Grand total sum
 */
int total_sum(int rows, int cols)
{
	int r;
	int total = 0;

	for (r = 1; r <= rows; r++)
	{
		/* Directly add the row's sum to total, bypassing double-accumulation */
		total += row_sum(r, cols);
	}

	return (total);
}

/* -- DO NOT Modify the code below this line -- */
int main(void)
{
	printf("%d\n", total_sum(3, 3));
	return (0);
}
