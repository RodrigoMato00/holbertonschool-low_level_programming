#include "lists.h"
#include <string.h>
#include <stdio.h>
/**
 *add_node - adds a new node at the beginning of a list_t
 *@head: head
 *@str: str
 *Return: algo
 */
list_t *add_node(list_t **head, const char *str)
{
	char *x;
	int a;
	list_t *jeje;

	jeje = malloc(sizeof(list_t));
	if (jeje == NULL)
		return (NULL);

	x = strdup(str);
	if (x == NULL)
	{
		free(jeje);
		return (NULL);
	}

	for (a = 0; str[a];)
		a++;

	jeje->str = x;
	jeje->len = a;
	jeje->next = *head;

	*head = jeje;

	return (jeje);
}
