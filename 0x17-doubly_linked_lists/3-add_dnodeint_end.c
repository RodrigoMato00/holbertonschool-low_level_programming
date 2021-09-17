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

	temporal = *head;

	if (!head)
		return (NULL);

	nuevo = malloc(sizeof(dlistint_t));

	if (!nuevo)
		return (NULL);

	nuevo->n = n;
	nuevo->next = NULL;

	if (!*head)
	{
		nuevo->prev = *head;
		*head = nuevo;
		return (nuevo);
	}
	while (temporal->next)
		temporal = temporal->next;
	temporal->next = nuevo;
	nuevo->prev = temporal;
	return (nuevo);
}
