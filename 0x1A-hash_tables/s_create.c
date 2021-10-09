#include "hash_tables.h"

/**
 *shash_table_create - crea una sorted hash table
 *@size: tama
 *Return: tamano de la sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash;
	unsigned long int a;

	ht = malloc(sizeof(shash_table_t));

	if (shash == NULL)
		return (NULL);

	shash->size = size;
	shash->array = malloc(sizeof(shash_node_t *) * size);

	if (shash->array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
		shash->array[a] = NULL;

	shash->shead = NULL;
	shash->stail = NULL;

	return (shash);
}
