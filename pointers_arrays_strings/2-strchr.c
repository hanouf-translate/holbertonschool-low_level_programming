#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: A pointer to the first occurrence of c,
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	/* Loop handles looking for characters and the '\0' itself */
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
		i++;
	}

	/* If c is the null terminator, return the pointer to it */
	if (s[i] == c)
	{
		return (&s[i]);
	}

	return (NULL);
}
