#include "lists.h"

/**
 *add_nodeint_end - add a new node in the end
 *@head: double pointer
 *@n: value of the new nod
 *Return: addres of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current;
	listint_t *new;

	current = *head;
	while (current && current->next != NULL)
		current = current->next;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (current)
		current->next = new;
	else
		*head = new;
	return (new);
}
