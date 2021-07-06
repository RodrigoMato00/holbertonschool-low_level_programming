#include "holberton.h"

/**
 * print_chessboard - print the chessboard, 2 array
 * @a: 2 array chars
 */

void print_chessboard(char (*a)[8])
{
	int d, e;

	d = 0;
	while (d < 8)
	{
		e = 0;
		while (e < 8)
		{
			_putchar(a[d][e]);
			e++;
		}
		_putchar('\n');
		d++;
	}
}
