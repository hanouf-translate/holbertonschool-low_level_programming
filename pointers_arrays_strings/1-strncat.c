#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string to append to
 * @src: The source string to append
 * @n: The maximum number of bytes to copy from src
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_length = 0;
	int i;

	/* Find the end of the dest string */
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}

	/* Copy at most n bytes from src */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];
	}

	/* Always ensure the final string is null-terminated */
	dest[dest_length + i] = '\0';

	return (dest);
}
