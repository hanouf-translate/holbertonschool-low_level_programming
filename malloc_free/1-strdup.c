#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: The string to replicate.
 *
 * Return: A pointer to the duplicated string,
 *         or NULL if str is NULL or if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* Allocate memory (+1 for the null terminator) */
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	/* Copy the string data */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
