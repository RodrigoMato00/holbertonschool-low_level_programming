#include "holberton.h"

/**
 * infinite_add - Add numbers
 * Description: This function add two numbers
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Buffer that stpre the result
 * @size_r: Size of the buffer
 * Return: The result of @n1 + @n2, if the result < @r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int c = 0, c1 = 0, c2 = 0, acum = 0;

	size_r--;

	while (*(n1 + c1) != '\0' || *(n2 + c2) != '\0')
	{
		if (*(n1 + c1) != '\0')
			c1++;
		if (*(n2 + c2) != '\0')
			c2++;
	}
	c1--;
	c2--;
	while (c1 >= 0 && c2 >= 0)
	{
		*(r + c) = ((*(n1 + c1) + *(n2 + c2) - 96 + acum) % 10) + 48;
		acum = ((*(n1 + c1) + *(n2 + c2) - 96) / 10);
		c++;
		c1--;
		c2--;
	}
	while (c1 >= 0)
	{
		*(r + c) = ((*(n1 + c1) - 48 + acum) % 10) + 48;
		acum = ((*(n1 + c1) - 48 + acum) / 10);
		c++;
		c1--;
	}
	while (c2 >= 0)
	{
		*(r + c) = ((*(n2 + c2) - 48 + acum) % 10) + 48;
		acum = ((*(n2 + c2) - 48 + acum) / 10);
		c++;
		c2--;
	}
	*(r + c) = acum + 48;
	if (c >= size_r)
	{
		return (0);
	}
	return (r);
}
