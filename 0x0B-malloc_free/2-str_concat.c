#include "holberton.h"
#include <stdlib.h>

/**
 * str_concat - concatenate strings using malloc
 * @s1: string 1
 * @s2: string 2
 * Return: pointer of concat string
 */

char *str_concat(char *s1, char *s2)
{
	char *a;
	int b, c, d, e;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (b = 0; s1[b] != '\0'; b++)
		;
	for (c = 0; s2[c] != '\0'; c++)
		;

	a = malloc((b * sizeof(*s1)) + (c * sizeof(*s2)) + 1);
	if (a == NULL)
		return (NULL);

	for (d = 0, e = 0; d < (b + c + 1); d++)
	{
		if (d < b)
			a[d] = s1[d];
		else
			a[d] = s2[e++];
	}

	return (a);
}
