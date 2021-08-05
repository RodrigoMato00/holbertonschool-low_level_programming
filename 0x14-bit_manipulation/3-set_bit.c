#include "main.h"

/**
 *set_bit - sets the value of a bit to 1 at a given index
 *@n: number decimal
 *@index: the position to change
 *Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int marcador;

	if (index > 64)
		return (-1);

	for (marcador = 1; index > 0; index--, marcador *= 2)
		;
	*n += marcador;

	return (1);
}
