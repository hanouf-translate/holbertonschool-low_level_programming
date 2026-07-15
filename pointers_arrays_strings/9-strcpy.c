#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src to the buffer pointed to dest
 * @dest: The destination buffer
 * @src: The source string to copy
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	/* Loop copy including the '\0' character */
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	/* Ensure we copy the final null terminator byte */
	dest[i] = '\0';

	return (dest);
}
