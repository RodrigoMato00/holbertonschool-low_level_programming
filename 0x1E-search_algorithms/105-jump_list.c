#include "search_algos.h"

/**
 *jump_list - searches for a value in an array
 *@list: pointer to the first element of the array
 *@value: value to search for
 *@size: size of the array
 *Return: index of the value or -1 if not found
 **/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *a, *jump;
	size_t pos, nsize;

	if (list == NULL)
		return (NULL);

	pos = 0;
	nsize = sqrt(size);

	for (a = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		a = jump;
		for (pos += nsize; jump->index < pos; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}

		printf("Value checked at index [%li] = [%i]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%li] and [%li]\n", a->index,
		jump->index);

	for (; a->index < jump->index && a->n < value; a = a->next)
		printf("Value checked at index [%ld] = [%d]\n", a->index, a->n);
	printf("Value checked at index [%li] = [%i]\n", a->index, a->n);

	return (a->n == value ? a : NULL);
}
