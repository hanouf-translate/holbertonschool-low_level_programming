#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to be modified
 *
 * Return: A pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	char seps[] = " \t\n,;.!?\"(){}";

	/* Loop through each character of the string */
	while (str[i] != '\0')
	{
		/* If it's a lowercase letter */
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			/* Capitalize if it's the very first character of the string */
			if (i == 0)
			{
				str[i] = str[i] - 32;
			}
			else
			{
				/* Check if the preceding character was a separator */
				for (j = 0; seps[j] != '\0'; j++)
				{
					if (str[i - 1] == seps[j])
					{
						str[i] = str[i] - 32;
						break;
					}
				}
			}
		}
		i++;
	}

	return (str);
}
