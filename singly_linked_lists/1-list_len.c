#include "lists.h"

/**
 * list_len - returns the number of elements in a list_t list
 * @h: pointer to the first node of the list
 *
 * Return: the number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
