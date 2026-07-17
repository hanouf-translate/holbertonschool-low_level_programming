#include "main.h"

/**
 * print_chessboard - Prints the chessboard
 * @a: Pointer to an 8x8 character array grid
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int col;

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			_putchar(a[row][col]);
		}
		_putchar('\n');
	}
}
