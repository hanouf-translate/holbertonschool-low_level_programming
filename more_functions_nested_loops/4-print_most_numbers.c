#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9 except 2 and 4
 *
 * Description: Loops from '0' to '9' using ASCII representation.
 * Skips '2' and '4'. Uses _putchar exactly twice.
 * Return: void
 */
void print_most_numbers(void)
{
	int num;

	for (num = '0'; num <= '9'; num++)
	{
		if (num != '2' && num != '4')
		{
			_putchar(num); /* First use of _putchar */
		}
	}
	_putchar('\n'); /* Second use of _putchar */
}
