#include "lists.h"

/**
 *print_listint_safe - fdfdfdfs
 *@head: fdfsdfsdfsdf
 *Return: fdsdfdsf
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *t = NULL;
	const listint_t *u = NULL;
	int v;
	int count;

	v = 0;
	t = head;

	if (head == NULL)
		exit(98);

	while (t)
	{
		printf("[%p] %d\n", (void *)t, t->n);
		v++;
		t = t->next;
		u = head;
		count = 0;

		while (count < v)
		{
			if (t == u)
			{
				printf("-> [%p] %d\n", (void *)t, t->n);
				return (v);
			}
			u = u->next;
			count++;
		}
	}
		return (v);
}
