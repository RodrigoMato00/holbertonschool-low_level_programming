#include "lists.h"
#include <stdio.h>

/**
 *print_list - print all elements of a llist_t
 *@h: head
 *Return: node
 */
size_t print_list(const list_t *h)
{

	const list_t *jeje;
	size_t  a;

	a = 0;
	jeje = h;
	while (jeje != NULL)
	{
		printf("[%d] %s\n", jeje ->len, jeje->str);
	        jeje = jeje->next;
		a ++;
	}
	return (a);
}
