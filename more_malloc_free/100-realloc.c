#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to previously allocated memory
 * @old_size: Old size in bytes
 * @new_size: New size in bytes
 *
 * Return: Pointer to the new memory block, or NULL if it fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_ptr;
	unsigned int i;
	unsigned int limit;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;
	limit = old_size;
	if (new_size < old_size)
		limit = new_size;

	i = 0;
	while (i < limit)
	{
		new_ptr[i] = old_ptr[i];
		i++;
	}

	free(ptr);

	return (new_ptr);
}
