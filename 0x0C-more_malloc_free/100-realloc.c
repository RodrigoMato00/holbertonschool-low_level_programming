#include "holberton.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory bloc
 * @ptr: A pointer to the memory previous allocat
 * @old_size: The size in bytes
 * @new_size: The size in bytes
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL-NULL.
 *         Otherwise - a pointer the realocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);

		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);

	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (i = 0; i < old_size && i < new_size; i++)
		filler[i] = *ptr_copy++;

	free(ptr);
	return (mem);
}
