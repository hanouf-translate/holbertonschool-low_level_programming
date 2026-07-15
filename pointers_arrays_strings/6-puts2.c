#include "main.h"

/**
 * puts2 - Prints every other character of a string, starting with the first
 * @str: The pointer to the string to print
 *
 * Return: void
 */
void puts2(char *str)
{
	int len = 0;
	int i;

	/* Find the total length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Loop through the string, incrementing index by 2 */
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
