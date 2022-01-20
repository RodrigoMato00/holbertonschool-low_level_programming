#include "search_algos.h"

/**
 *muv_list - searches for a value in an array
 *@list: pointer to the first element of the array
 *@value: value to search for
 *@size: size of the array
 *Return: index of the value or -1 if not found
 **/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *a, *muv;
	size_t pos, nsize;

	if (!list)
		return (NULL);

	pos = 0;
	nsize = sqrt(size);

	for (a = muv = list; muv->index + 1 < size && muv->n < value;)
	{
		a = muv;
		for (pos += nsize; muv->index < pos; muv = muv->next)
		{
			if (muv->index + 1 == size)
				break;
		}

		printf("Value checked at index [%li] = [%i]\n", muv->index, muv->n);
	}

	printf("Value found between indexes [%li] and [%li]\n", a->index,
		muv->index);

	for (; a->index < muv->index && a->n < value; a = a->next)
		printf("Value checked at index [%ld] = [%d]\n", a->index, a->n);
	printf("Value checked at index [%li] = [%i]\n", a->index, a->n);

	return (a->n == value ? a : NULL);
}
