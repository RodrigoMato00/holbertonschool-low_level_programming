#include <string.h>
#include "lists.h"

/**
 *add_node_end - adds a new node at the end of a list_t
 *@head: head
 *@str: str
 *Return: head
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *x;
	int a;
	list_t *jeje, *last;

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
	jeje->next = NULL;

	if (*head == NULL)
		*head = jeje;

	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;

		last->next = jeje;
	}
	return (*head);
}
