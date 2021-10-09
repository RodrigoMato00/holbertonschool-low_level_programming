#include "hash_tables.h"

/**
 *shash_table_print - imprime la hash table
 *@ht: hash table a imprimir
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *nodo;

	if (ht == NULL)
		return;

	nodo = ht->shead;

	printf("{");

	while (nodo != NULL)
	{
		printf("'%s': '%s'", nodo->key, nodo->value);
		nodo = nodo->snext;
		if (nodo != NULL)
			printf(", ");
	}
	printf("}\n");
}
