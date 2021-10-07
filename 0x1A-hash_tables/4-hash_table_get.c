#include "hash_tables.h"

/**
 *hash_table_get - bbbbbbbbbb
 *@ht: odsijfs
 *@key: dsjfskdlfm
 *Return: dijfsdpojf
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int ind;
	hash_node_t *buscador;

	if (ht == NULL || key == NULL)
		return (NULL);

	ind = key_index((const unsigned char *)key, ht->size);

	if (ht->array[ind] == NULL)
		return (NULL);

	buscador = ht->array[ind];

	while (buscador)
	{
		if (strcmp(buscador->key, key) == 0)
			return (buscador->value);
		buscador = buscador->next;
	}
	return (NULL);
}
