#include "main.h"

/**
 * _strncpy - Copies a string up to n bytes
 * @dest: The destination buffer to copy the string to
 * @src: The source string to copy
 * @n: The maximum number of bytes to copy from src
 *
 * Return: A pointer to the destination buffer dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
