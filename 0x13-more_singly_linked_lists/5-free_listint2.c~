#include "lists.h"

/**
 *free_listint2 - free a listint_t
 *@head: double pointer
 *Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *h = NULL;

	if (*head)
	{
		while (*head)
		{
			h = *head;
			*head = h->next;
			free(h);
		}
	}
}
