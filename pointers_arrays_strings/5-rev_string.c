#include "main.h"

/**
 * rev_string - Reverses a string permanently in memory
 * @s: The pointer to the string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0;
	int left = 0;
	int right;
	char tmp;

	/* 1. Find the total length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* 2. Set the right index to the last valid character */
	right = len - 1;

	/* 3. Swap working inward until pointers cross in the center */
	while (left < right)
	{
		tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;

		left++;
		right--;
	}
}
