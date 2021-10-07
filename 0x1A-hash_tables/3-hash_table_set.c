#include "hash_tables.h"

/**
 *hash_table_set - anade un elemento a la hash
 *@ht: elemento a anadir a la tabla
 *@key: key a anadir
 *@value: valor para almacenar la key
 *Return: 0 fallo, 1 exitosamente
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *par;
	hash_node_t *temp;
	unsigned long int ind;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	ind = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[ind];

	if (temp != NULL)
	{
		while (temp)
		{
			if (strcmp(temp->key, key) == 0)
			{
				temp->value = strdup(value);
				return (1);
			}
			temp = temp->next;
		}
	}
	par = malloc(sizeof(hash_node_t));
	if (par == NULL)
		return (0);

	par->key = strdup(key);
	par->value = strdup(value);
	par->next = NULL;

	ht->array[ind] = par;

	if (ht->array[ind] != NULL)
		par->next = ht->array[ind];
	ht->array[ind] = par;

	return (1);
}
