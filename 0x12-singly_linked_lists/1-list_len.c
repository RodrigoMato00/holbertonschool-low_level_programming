#include "lists.h"

/**
 *list_len - returns the number of elements in a linked
 *@h: head
 *Return: number of elements
 */
size_t list_len(const list_t *h)
{
	const list_t *jeje;
	size_t a;

	a = 0;
	jeje = h;
	while (jeje != NULL)
	{
		jeje = jeje->next;
		a++;
	}
	return (a);
}
