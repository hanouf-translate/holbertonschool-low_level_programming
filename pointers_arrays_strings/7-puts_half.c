#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line
 * @str: The pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int start;
	int i;

	/* Find the total length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Apply the formula to find the starting index */
	start = len - ((len + 1) / 2);

	/* Print from the starting index to the end of the string */
	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
