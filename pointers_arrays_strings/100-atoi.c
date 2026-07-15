#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The pointer to the string
 *
 * Return: The converted integer value, or 0 if no numbers are found
 */
int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int found_digit = 0;

	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{
			/* Do nothing, plus signs do not flip direction */
		}
		else if (*s >= '0' && *s <= '9')
		{
			found_digit = 1;
			/* Build res as a negative number to protect against overflow */
			res = (res * 10) - (*s - '0');
		}
		else if (found_digit)
		{
			/* We hit a non-digit character AFTER finding numbers: stop! */
			break;
		}
		s++;
	}

	/* Adjust the final result matching our sign tracker */
	if (sign > 0)
	{
		return (-res);
	}

	return (res);
}
