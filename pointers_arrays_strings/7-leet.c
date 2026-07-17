#include "main.h"

/**
 * leet - Encodes a string into 1337 (leet speak)
 * @str: The string to encode
 *
 * Return: A pointer to the modified string
 */
char *leet(char *str)
{
	int i = 0;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	/* Loop 1: Traverse the input string */
	while (str[i] != '\0')
	{
		/* Loop 2: Search for matches in our replacement lists */
		for (j = 0; j < 10; j++)
		{
			/* Our single allowed IF statement */
			if (str[i] == letters[j])
			{
				str[i] = numbers[j];
			}
		}
		i++;
	}

	return (str);
}
