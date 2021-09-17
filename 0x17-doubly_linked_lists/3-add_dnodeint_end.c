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

	if(*head == NULL)
	{
		*head = nuevo;
		nuevo->next = NULL;
		nuevo->prev = NULL;
		return (nuevo);
	}

	while (temporal->next != NULL)
	{
		temporal = temporal->next;
	}

	temporal->next = nuevo;
	nuevo->prev = temporal;
	nuevo->next = NULL;


	return (nuevo);

}
