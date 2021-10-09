#include "hash_tables.h"

/**
 *shash_table_delete - borrar la hash table
 *@ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	hash_node_t *nodo;
	unsigned long int corredor;

	corredor = 0;

	if (ht == NULL)
		return;

	while (corredor < ht->size)
	{

		while (ht->array[corredor] != NULL)
		{
			nodo = ht->array[corredor];
			free(nodo->key);
			free(nodo->value);
			ht->array[corredor] = ht->array[corredor]->next;
			free(nodo);
		}
		corredor++;
	}
	free(ht->array);
	free(ht);
}
