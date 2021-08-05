#include "main.h"

/**
 *flip_bits - serch number of bits you would need to flip to get from one numb
 *@n: number
 *@m: chang number
 *Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int marcador;
	unsigned long int contador;

	marcador = 0;
	contador = 0;

	n = n ^ m;

	while (n)
	{
		if (marcador & n)
			contador++;
		n = n >> 1;
	}
	return (contador);
}
