#include "holberton.h"

/**
 * wildcmp - compares two strings
 * Description: if are identical
 * Return: 1 if are identical, otherwise 0
 * @s1: first string
 * @s2: second string
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, (s2 + 1)));
	if (*s1 == '\0' || '\0')
		return (0);
	if (*s1 == *s2)
		return (wildcmp((s1 + 1), (s2 + 1)));
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, (s2 + 1)));
		if (wildcmp(s1, s2 + 1) == 1)
			return (1);
		return (wildcmp(s1 + 1, s2));
	}
	return (0);
}
