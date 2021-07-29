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
	list_t *new, *last;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	x = strdup(str);
	if (x == NULL)
	{
		free(new);
		return (NULL);
	}

	for (a = 0; str[a];)
		a++;

	new->str = x;
	new->len = a;
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;

		last->next = new;
	}
	return (*head);
}
