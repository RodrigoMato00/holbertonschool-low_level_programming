#include "lists.h"

/**
 *add_dnodeint_end - sldjfskldmsdmvsoñdlv
 *@head: dkfjsxmfpsdmcpsodcm
 *@n: adkapozc,podc,ñlzc
 *Return: sdkpocsd,cpsdopfkdpozf,
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temporal;
	dlistint_t *nuevo;

	nuevo = malloc(sizeof(dlistint_t));

	if (nuevo == NULL)
		return (NULL);

	nuevo->n = n;
	nuevo->next = NULL;

	if(*head == NULL)
	{
		nuevo->prev = NULL;
		*head = nuevo;
	}

	else
	{
		temporal = *head;
		while (temporal->next != NULL)
		{
			temporal = temporal->next;
		}
		nuevo->prev = temporal;
		nuevo->next = nuevo;
	}

	return (nuevo);

}
