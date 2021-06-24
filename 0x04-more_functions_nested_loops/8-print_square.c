#include "holberton.h"

/**
 * print_square - Prints a squareusing the character #.
 * @size: The size of the square.
 */
void print_square(int size)
{
int a, b;

if (size > 0)
{
for (a = 0; a < size; a++)
{
for (b = 0; b < size; b++)
_putchar('#');

if (a == size - 1)
continue;
_putchar('\n');
}
}

_putchar('\n');
}
