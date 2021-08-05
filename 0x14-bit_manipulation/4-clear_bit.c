#include "main.h"

/**
 *clear_bit - sets the value of a bit to 0 at a given index
 *@n: number
 *@index: index to 0
 *Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int marcador;

	marcador = 1;

	if (*n == '\0')
		return (-1);

	if (index > sizeof(n) * 8)
		return (-1);

	*n = ~*n;
	marcador = marcador << index;
	*n |= marcador;
	*n = ~*n;

	return (1);
}
