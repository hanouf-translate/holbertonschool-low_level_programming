#include <stdio.h>

int main(void)
{
	printf("Size of a char: %lu bytes(s)\n", sizeod(char));
	printf("Size of an int: %lu bytes(s)\n", sizeof(int));
	printf("Size of a long int: %lu bytes(s)", sizeof(long int));
	printf("Size of a long long int: %lu bytes(s)", sizeof(long long int));
	printf("Size of a float: %lu bytes(s)", sizeof(float));

	return (0);
}
