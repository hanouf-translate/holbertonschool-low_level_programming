#include <stdio.h>
#include "main.h"

/**
 * main - Prints the program's name, followed by a new line.
 * @argc: Number of command line arguments (unused).
 * @argv: Array of command line argument strings.
 *
 * Return: Always 0 (Success).
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
