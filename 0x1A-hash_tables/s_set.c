#include "hash_tables.h"

/**
 *hash_table_set - anade un elemento a la hash
 *@ht: elemento a anadir a la tabla
 *@key: key a anadir
 *@value: valor para almacenar la key
 *Return: 0 fallo, 1 exitosamente
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *par;
	hash_node_t *temp;
	unsigned long int ind;
	char *c;

	if (key == NULL || value == NULL || ht == NULL)
		return (0);

	c = strdup(value);
	if (c == NULL)
		return (0);

	ind = key_index((const unsigned char *)key, ht->size);
	temp = ht->shead;

	while (temp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(temp->value);
			temp->value = c;
			return (1);
		}
		temp = temp->snext;
	}

	par = malloc(sizeof(shash_node_t));
	if (par == NULL)
	{
		free(c);
		return (0);
	}
	par->key = strdup(key);
	if (par->key == NULL)
	{
		free(c);
		free(par);
		return (0);
	}
	par->value = c;
	par->next = ht->array[ind];
	ht->array[ind] = par;

	if (ht->shead == NULL)
	{
		par->sprev = NULL;
		par->snext = NULL;
		ht->shead = par;
		ht->stail = par;
	}

	else if (strcmp(ht->shead->key, key) > 0)
	{
		par->sprev = NULL;
		par->snext = ht->shead;
		ht->shead->sprev = par;
		ht->shead = par;
	}

	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		par->sprev = temp;
		par->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = par;
		else
			temp->snext->sprev = par;
		temp->snext = par;
	}

	return (1);
}
