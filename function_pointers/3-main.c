#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Performs simple arithmetic operations.
 * @argc: Argument count.
 * @argv: Argument vector (array of strings).
 *
 * Return: 0 on success, exits with 98, 99, or 100 on error.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_func)(int, int);

	/* Step 1: Validate argument count */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* Step 2: Convert string input to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	/* Step 3: Fetch the operation function pointer */
	op_func = get_op_func(argv[2]);

	/* Step 4: Validate operator string */
	if (op_func == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	/* Step 5: Prevent illegal math (Division / Modulo by Zero) */
	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	/* Step 6: Execute function and print output */
	result = op_func(num1, num2);
	printf("%d\n", result);

	return (0);
}
