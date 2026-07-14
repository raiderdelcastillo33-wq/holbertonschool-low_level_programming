#include "function_pointers.h"

/**
 * print_name - Prints a name using a callback function
 * @name: The name to print
 * @f: Pointer to the function used to print the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
