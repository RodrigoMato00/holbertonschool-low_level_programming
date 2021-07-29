#include "lists.h"

/**
 *free_list - frees a list_t
 *@head: head is head
 */
void free_list(list_t *head)
{
	list_t *jeje;

	while (head)
	{
		jeje = head->next;
		free(head->str);
		free(head);
		head =  jeje;
	}
}
