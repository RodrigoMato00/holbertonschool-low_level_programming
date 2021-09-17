#include "lists.h"

/**
 *sum_dlistint - apweokteopgksopdkgsopkeg
 *@head: ropkeopgkeopkgekop
 *Return: pwioejkwiopdkfopwkdfopwkdf
 */
int sum_dlistint(dlistint_t *head)
{
	int a;

	a = 0;

	while (head)
	{
		a += head->n;
		head = head->next;
	}

	return (a);
}
