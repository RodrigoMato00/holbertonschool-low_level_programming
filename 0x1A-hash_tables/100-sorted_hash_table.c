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

        shash = malloc(sizeof(shash_table_t));

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

/**
 *shash_table_get - fogksjkckckfk
 *@ht pfsdkfmspokdfpok
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

/**
 *shash_table_set - anade un elemento a la hash
 *@ht: elemento a anadir a la tabla
 *@key: key a anadir
 *@value: valor para almacenar la key
 *Return: 0 fallo, 1 exitosamente
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *par;
	shash_node_t *temp;
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
		if (strcmp(temp->key, key) == 0)
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

/**
 *shash_table_delete - borrar la hash table
 *@ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *shash;
	shash_node_t *nodo;
	shash_node_t *temp;

	shash = ht;

	if (ht == NULL)
		return;

	nodo = ht->shead;
	while (nodo)
	{
		temp = nodo->snext;
		free(nodo->key);
		free(nodo->value);
		free(nodo);
		nodo = temp;
	}

	free(shash->array);
	free(shash);
}
