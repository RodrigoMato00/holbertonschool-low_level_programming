#include "lists.h"

/**
 *dlistint_len - jdfksdjfsdcklmflvmklfv
 *@h: ipdfjoisjdfiosdfoisd
 *Return: ksdfsñld,ñlsd,ñlsd
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temporal;
	size_t contador;

	temporal = h;

	while (temporal && temporal->prev)
	{
		temporal = temporal->prev;
	}

	for (contador = 0; temporal; contador++, temporal = temporal->next)
		;

	return (contador);
}
