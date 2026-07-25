#include "main.h"

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of elements in the array.
 * @size: Size in bytes of each element.
 *
 * Return: Pointer to allocated memory.
 *         If nmemb == 0, size == 0, or malloc fails, returns NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total_size, i;

	/* Return NULL if nmemb or size is 0 */
	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	/* Allocate memory using malloc */
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	/* Set every byte to zero */
	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}
