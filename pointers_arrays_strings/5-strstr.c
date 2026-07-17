#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring
 * @haystack: The main string to look into
 * @needle: The substring to search for
 *
 * Return: A pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j;

	/* Edge case: an empty needle matches the start of haystack */
	if (needle[0] == '\0')
	{
		return (haystack);
	}

	while (haystack[i] != '\0')
	{
		j = 0;

		/* Check if the substring pattern matches starting at haystack[i] */
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
		{
			j++;
		}

		/* If we fully matched needle up to its null byte, success! */
		if (needle[j] == '\0')
		{
			return (&haystack[i]);
		}

		i++;
	}

	return (NULL);
}
