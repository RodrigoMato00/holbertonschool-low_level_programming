#include "lists.h"

/**
 *free_listint - free a listint_t
 *@head: head of linked list
 *Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *h;

	while (head != NULL)
	{
		h = head;
		head = head->next;
		free(h);
	}
}
