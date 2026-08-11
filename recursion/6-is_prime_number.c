#include "main.h"

/**
 * check_prime - Recursively tests if n is divisible by divisor i.
 * @n: The target integer to evaluate.
 * @i: The current divisor being tested (starts at 2).
 *
 * Return: 1 if n is prime, 0 if divisible or overshot.
 */
int check_prime(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - Checks if an integer is a prime number.
 * @n: The integer to evaluate.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (check_prime(n, 2));
}
