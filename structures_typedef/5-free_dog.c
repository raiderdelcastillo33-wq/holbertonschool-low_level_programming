#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog_t structure
 * @d: Dog structure to free
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
