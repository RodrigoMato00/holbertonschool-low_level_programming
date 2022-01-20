#include "search_algos.h"

/**
 *linear_skip - linear search algorithm
 *@list: list to search
 *@value: value to search for
 *Return: index of value or -1 if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *a, *muv;

	if (!list)
		return (NULL);

	for (a = muv = list; muv->next != NULL && muv->n < value;)
	{
		a = muv;
		if (muv->express != NULL)
		{
			muv = muv->express;
			printf("Value checked at index [%ld] = [%d]\n",
					muv->index, muv->n);
		}

		else
		{
			for (; muv->next != NULL;)
				muv = muv->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			a->index, muv->index);

	for (; a->index < muv->index && a->n < value;  a = a->next)
		printf("Value checked at index [%ld] = [%d]\n", a->index, a->n);

	printf("Value checked at index [%ld] = [%d]\n", a->index, a->n);

	return (a->n == value ? a : NULL);
}
