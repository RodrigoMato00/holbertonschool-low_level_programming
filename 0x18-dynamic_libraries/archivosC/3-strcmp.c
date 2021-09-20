#include "main.h"

/**
 * _strcmp - Compare strings
 * Description: This function compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: @n bytes of @src
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s2 > *s1)
			return ((*s2 - *s1) * -1);
		s1++;
		s2++;
	}
	return (0);
}
