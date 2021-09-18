#include "lists.h"

/**
 *delete_dnodeint_at_index- opekgopekrg
 *@head: osidjfoiasjdfopaisjf
 *@index: diogfjzsdojgnauioprjiag
 *Return: rgahehastusthustu
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *nodo = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (!nodo)
			return (-1);
		nodo = nodo->next;
	}

	if (nodo == *head)
	{
		*head = nodo->next;
		if (*head)
			(*head)->prev = NULL;
	}

	else
	{
		nodo->prev->next = nodo->next;
		if (nodo->next)
			nodo->next->prev = nodo->prev;
	}

	free(nodo);
	return (1);
}
