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
	dlistint_t *nuevo, *siguiente, *anterior;
	unsigned int a = 1;

	nuevo = malloc(sizeof(dlistint_t));
	if (nuevo == NULL)
		return (NULL);
	nuevo->n = n;
	if (*h == NULL)
	{
		nuevo->prev = NULL;
		nuevo->next = NULL;
		*h = nuevo;
		return (nuevo);
	}
	anterior = *h;
	if (idx == 0)
	{
		*nuevo = *add_dnodeint(h, n);
		return (nuevo);

	}
	while (a < idx && anterior != NULL)
	{
		anterior = anterior->next;
		a++;
	}

	if (anterior == NULL && a < idx)
		return (NULL);
	if (anterior == NULL && a == idx)
	{
		*nuevo = *add_dnodeint_end(h, n);
		return (nuevo);
	}
	siguiente = anterior->next;
	anterior->next = nuevo;
	nuevo->prev = anterior;
	nuevo->next = siguiente;
	nuevo = *h;
	return (nuevo);
}
