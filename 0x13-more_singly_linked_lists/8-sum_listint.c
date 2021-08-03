#include "lists.h"

/**
 *sum_listint - returns the sum of all the data (n) of a listint_t linked list
 *@head: address of the linked list
 *Return: sum the linked list
 */
int sum_listint(listint_t *head)
{
	int sum;
	listint_t *co;

	sum = 0;
	co = head;

	while (co != NULL)
	{
		sum += co->n;
		co = co->next;
	}
	return (sum);
}
