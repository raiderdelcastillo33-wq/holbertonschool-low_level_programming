#include <string.h>
#include "3-calc.h"

/**
 * get_op_func - Selects the correct operation function
 * @s: Operator passed to the program
 *
 * Return: Pointer to the matching function, or NULL
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL && strcmp(ops[i].op, s) != 0)
		i++;

	return (ops[i].f);
}
