#include "main.h"

/**
 * print_square - Prints a square using the '#' character, followed by a newline
 * @size: The width and height size of the square matrix
 *
 * Return: void
 */
void print_square(int size)
{
	int row, col;

	if (size > 0)
	{
		for (row = 0; row < size; row++)
		{
			for (col = 0; col < size; col++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
