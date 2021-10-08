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

	if (key == NULL || value == NULL || ht == NULL)
		return (0);

	ind = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[ind];


	while (temp)
	{
		if (strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}

	par = malloc(sizeof(hash_node_t));

	if (par == NULL)
		return (0);
	par->key = strdup(key);
	par->value = strdup(value);
	par->next = NULL;

	if (ht->array[ind] == NULL)
	{
		ht->array[ind] = par;
		return (1);
	}
	temp = ht->array[ind];
	par->next = temp;
	ht->array[ind] = par;
	return (1);
}
