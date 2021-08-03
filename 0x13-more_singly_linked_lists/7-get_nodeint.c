#include "lists.h"

/**
 *get_nodeint_at_index - get the nth af a linked list
 *@head: pointer to head node
 *@index: index is find  in linked list, start at 0
 *Return: eturns the nth node of a listint_t
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int my_node;

	for (my_node = 0; my_node < index; my_node++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}
	return (head);
}
