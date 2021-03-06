#include "lists.h"

/**
 *delete_nodeint_at_index - deletes the node at index index of a linked list
 *@head: address of the linked list
 *@index: node deleted
 *Return: 1 is success, -1 fail.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *h;
	listint_t *c;

	i = 0;
	c = *head;
	if (*head == NULL)
		return (-1);

	while (i < index)
	{
		i++;
		h = c;
		if (c->next)
			c = c->next;
		else
			return (-1);
	}

	if (index == 0)
		*head = c->next;
	else if (c->next)
		h->next = c->next;
	else
		h->next = NULL;

	free(c);
	return (1);
}
