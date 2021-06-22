#include "holberton.h"
#include <stdio.h>
/**
 * print_to_98 - Print all natural numbers from n to 98
 * @n: int type number
 */
void print_to_98(int n)
{
	int start = n;

	while (start != 98)
	{
		printf("%d", start);
		putchar(',');
		putchar(' ');
		if (n > 98)
			start--;
		else
			start++;
	}
	printf("98\n");
}
