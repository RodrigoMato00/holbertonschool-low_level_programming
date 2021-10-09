#include "hash_tables.h"

/**
 *shash_table_print_rev - imprime la hash table
 *@ht: hash table a imprimir
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *nodo;

	if (ht == NULL)
		return;

	nodo = ht->stail;

	printf("{");

	while (nodo != NULL)
	{

		printf("'%s': '%s'", nodo->key, nodo->value);
		nodo = nodo->sprev;
		if (nodo != NULL)
			printf(", ");
	}

	printf("}\n");
}
