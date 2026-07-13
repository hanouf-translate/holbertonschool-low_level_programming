#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: The string to be printed in reverse
 *
 * Return: void
 */
void print_rev(char *s)
{
	int len = 0;
	int i;

	/* Find the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Walk backward from the last character (len - 1) down to 0 */
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
