#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings into a newly allocated memory space.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the newly allocated memory containing concatenated
 *         strings, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	unsigned int len1 = 0, len2 = 0;
	unsigned int i, j;

	/* Treat NULL inputs as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate length of s1 */
	while (s1[len1] != '\0')
		len1++;

	/* Calculate length of s2 */
	while (s2[len2] != '\0')
		len2++;

	/* Allocate enough memory for both strings plus the null terminator */
	concat_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat_str == NULL)
		return (NULL);

	/* Copy s1 into the new memory space */
	for (i = 0; i < len1; i++)
		concat_str[i] = s1[i];

	/* Copy s2 right after s1 */
	for (j = 0; j < len2; j++, i++)
		concat_str[i] = s2[j];

	/* Append the null terminator */
	concat_str[i] = '\0';

	return (concat_str);
}
