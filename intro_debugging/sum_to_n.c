#include <stdio.h>

/**
 * sum_to_n - Computes the sum of all integers from 1 to n
 * @n: The stopping number
 *
 * Return: The total sum
 */
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	/* Changed loop condition from 'i < n' to 'i <= n' to include n */
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	/* Changed from 'return n;' to return the actual computed sum */
	return (sum);
}

/* -- DO NOT Modify the code below this line -- */
int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}
