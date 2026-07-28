#include <stddef.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name using a given function pointer.
 * @name: Name of the person (string).
 * @f: Pointer to a function that takes a char pointer and returns void.
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
