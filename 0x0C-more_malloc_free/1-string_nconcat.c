#include <stdlib.h>
#include <stddef.h>
#include "holberton.h"
#include <stdio.h>

/**
 * string_nconcat - blablabla
 * @s1: string 1
 * @s2: string 2
 * @n: bytes to include of s2
 * Return: NULL fail, else pointer to malloc memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int strlen1, a, b;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	strlen1 = (unsigned int)_strlen(s1);
	p = malloc((strlen1 + n + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (a = 0, b = 0; a < (strlen1 + n); a++)
	{
		if (a < strlen1)
			p[a] = s1[a];
		else
			p[a] = s2[b++];
	}
	p[a] = '\0';

	return (p);
}

/**
 * _strlen - find length string
 * @s: string
 * Return: length string
 */

unsigned int _strlen(char *s)
{
	unsigned int a;

	for (a = 0; s[a] != '\0'; a++)
		;
	return (a);
}
