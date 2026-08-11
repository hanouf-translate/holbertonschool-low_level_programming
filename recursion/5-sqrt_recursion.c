#include "main.h"

/**
 * _sqrt_helper - Tests numbers starting from i to find the square root.
 * @n: The target number.
 * @i: The current guess.
 *
 * Return: The square root if found, or -1 if overshot/no natural root.
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: Natural square root, or -1 if n does not have one / is negative.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_helper(n, 1));
}
