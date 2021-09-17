#include "lists.h"

/**
 *add_dnodeint- ofjalkmdlakmlkamd
 *@head: dfjkñaldfñlad,
 *@n: lskdjmflskmdlvksmvñls
 *Return: sdjflkñkmpvsmvñls
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *i;

	i = *head;
	i = malloc(sizeof(dlistint_t));

	if (i == NULL)
		return (NULL);

	i->n = n;

	if (*head)
	(*head)->prev = i;
	i->prev = NULL;
	i->next = *head;
	*head = i;
	return (i);
}
