#include "main.h"

/**
 * print_numbers - Prints numbers from 0 to 9 followed by a new line
 *
 * Description: Loops from '0' to '9' using ASCII representation.
 * Uses _putchar exactly twice.
 * Return: void
 */
void print_numbers(void)
{
	int num;

	for (num = '0'; num <= '9'; num++)
	{
		_putchar(num); /* First use of _putchar */
	}
	_putchar('\n'); /* Second use of _putchar */
}
