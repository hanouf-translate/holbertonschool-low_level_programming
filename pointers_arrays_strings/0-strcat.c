#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string to be appended to
 * @src: The source string to append
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i = 0;

	/* Find the end of the dest string (where '\0' sits) */
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/* Copy src characters over to dest, starting at dest's null byte */
	while (src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}

	/* Explicitly append the terminating null byte at the end */
	dest[dest_len] = '\0';

	return (dest);
}
