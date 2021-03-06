#include "lists.h"

/**
 *pop_listint - deletes the head node of a listint_t linked list
 *@head: address
 *Return: head nods
 */
int pop_listint(listint_t **head)
{
	int number;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	number = temp->n;
	*head = temp->next;
	free(temp);

	return (number);
}
