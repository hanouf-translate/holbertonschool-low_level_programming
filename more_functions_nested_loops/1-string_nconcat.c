#include "main.h"

/**
 * string_nconcat - Concatenates s1 and the first n bytes of s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes from s2 to concatenate.
 *
 * Return: Pointer to newly allocated memory containing s1 + n bytes of s2.
 *         If memory allocation fails, returns NULL.
 *         If NULL is passed for s1 or s2, it is treated as an empty string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

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

	/* If n is greater than or equal to len2, use entire s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory for s1 + n bytes of s2 + 1 for '\0' */
	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	/* Copy s1 into concat */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copy first n bytes of s2 into concat */
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	/* Null-terminate the string */
	concat[i + j] = '\0';

	return (concat);
}
