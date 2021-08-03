#include "lists.h"

/**
 *print_listint_safe - fdfdfdfs
 *@head: fdfsdfsdfsdf
 *Return: fdsdfdsf
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *h;
	const listint_t *c;
	size_t num;

	c = head;
	if (c == NULL)
		exit(98);

	num = 0;
	while (c != NULL)
	{
		h = c;
		c = c->next;
		num++;
		printf("[%p] %d\n", (void *)h, h->n);

		if (h < c)
		{
			printf("-> [%p] %d\n", (void *)h, h->n);
			break;
		}
	}
	return (num);
}
