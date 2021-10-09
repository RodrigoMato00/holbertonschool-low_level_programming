#include "hash_tables.h"

/**
 *shash_table_get - fogksjkckckfk
 *@ht: pfsdkfmspokdfpok
 *@key: kfjjgjfkcmkfkdk
 *Return: kgkfkdjjrkkf
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int ind;
	shash_node_t *buscador;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	ind = key_index((const unsigned char *)key, ht->size);
	if (ind >= ht->size)
		return (NULL);

	buscador = ht->shead;
	while (buscador != NULL && strcmp(buscador->key, key) != 0)
		buscador = buscador->snext;

	return ((buscador == NULL) ? NULL : buscador->value);
}
