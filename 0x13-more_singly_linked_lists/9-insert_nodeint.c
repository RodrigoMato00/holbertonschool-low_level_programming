#include "lists.h"

/**
 *insert_nodeint_at_index - insert a new node
 *@head: addres of the linked list
 *@idx: is the index
 *@n: valiu of new node
 *Return: address new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *co;
	listint_t *new_node;
	unsigned int node = 0;
	unsigned int contador = 0;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	co = *head;
	while (co != NULL)
	{
		node++;
		co = co->next;
	}

	if (node < idx)
	{
		free(new_node);
		return (NULL);
	}

	co = *head;
	if (contador == idx)
	{
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}
	while (contador != idx - 1)
	{
		co = co->next;
		contador++;
	}
	new_node->next = co->next;
	co->next = new_node;
	return (new_node);
}
