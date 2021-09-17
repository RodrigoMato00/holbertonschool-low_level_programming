#include "lists.h"

/**
 *insert_dnodeint_at_index - wiojgiowfiwofjiowjgiowjrg
 *@h: iowjdgwiopgjiopeg
 *@idx: owhfuowienhfouiwenfonwf
 *@n: ieorjgioemjeriogeiormgemiog
 *Return: kidgjiopsgmkifio
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nuevo, *nodo = *h;
	unsigned int a = 1;

	if (!h)
		return (NULL);
	if (*h == NULL && idx != 0)
		return (NULL);
	nuevo = malloc(sizeof(dlistint_t));
	if (nuevo == NULL)
		return (NULL);
	nuevo->n = n;
	if (idx == 0)
	{
		if (*h)
			nodo->prev = nuevo;
		*h = nuevo;
		nuevo->prev = NULL;
		nuevo->next = nodo;
		return (nuevo);
	}
	for (a = 1; a < idx; a++)
	{
		nodo = nodo->next;
		if (nodo == NULL)
		{
			free(nuevo);
			return (NULL);
		}
	}
	nuevo->prev = nodo;
	nuevo->next = nodo->next;
	if (nodo->next)
		nodo->next->prev = nuevo;
	nodo->next = nuevo;
	return (nuevo);
}
