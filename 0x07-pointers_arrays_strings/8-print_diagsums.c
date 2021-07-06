#include "holberton.h"
#include <stdio.h>
/**
 * print_diagsums - Print the sum of the 2 diagonals of a square matrix of ints
 * @a: 2d array of int types
 * @size: size of array (square)
 */

void print_diagsums(int *a, int size)
{
	int b, c, d;

	b = 0;
	c = 0;
	d = size * size;
	while (b < d)
	{
		if (b % (size + 1) == 0)
			c += a[b];
		b++;
	}
	printf("%d, ", c);

	c = 0;
	b = 0;
	while (b < d)
	{
		if (b % (size - 1) == 0 && b != (d - 1) && b != 0)
			c += a[b];
		b++;
	}
	printf("%d\n", c);
}
