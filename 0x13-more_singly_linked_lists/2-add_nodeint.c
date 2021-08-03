#include "lists.h"

/**
 *add_nodeint - add a new node in the listint_t
 *@head: doubled pointer
 *@n: new node
 *Return: new nod address
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *h;
	listint_t *new;

	h = *head;
	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);
	new->n = n;
	*head = new;

	if (h == NULL)
		new->next = NULL;
	else
		(new->next = h);

	return (new);
}
