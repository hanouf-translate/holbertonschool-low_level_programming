#include "main.h"

/**
 * print_triangle - Prints a right-aligned triangle followed by a newline
 * @size: The size depth of the triangle base
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row, spaces, hashes;

	if (size > 0)
	{
		for (row = 0; row < size; row++)
		{
			for (spaces = 0; spaces < (size - (row + 1)); spaces++)
			{
				_putchar(' ');
			}
			for (hashes = 0; hashes < (row + 1); hashes++)
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
