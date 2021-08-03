#include "lists.h"

/**
 *reverse_listint - reverses a listint_t
 *@head: addres to the linked list
 *Return: pointer to the first node of the reversed the list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pr;
	listint_t *ne;

	pr = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);
	for (ne = (*head)->next; ne; ne = (*head)->next)
	{
		(*head)->next = pr;
		pr = *head;
		*head = ne;
	}
	(*head)->next = pr;
	return (*head);
}
