#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Pointer to the pointer to change.
 * @to: String to point to.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
