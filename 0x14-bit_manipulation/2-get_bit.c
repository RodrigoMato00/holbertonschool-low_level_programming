#include "main.h"

/**
 *get_bit - returns the value of a bit at a given index
 *@n: the number
 *@index: the index to return the value
 *Return: the value of a bit in index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int a;

	for (a = 0; a < index; a++)
		n >>= 1;
	if (a > ((sizeof(unsigned long int) * 8) - 1))
		return (-1);
	return (n & 1);
}
