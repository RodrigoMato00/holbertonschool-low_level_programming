#include "holberton.h"

/**
 * get - gets length string
 * @s: string
 * Return: return length string
 */

int get(char *s)
{
	if (*s == '\0')
		return (1);
	else
		return (1 + get(++s));
}

/**
 * co - recursive check of palindrome
 * @s: string
 * @l: length of string
 * Return: 1 if palindrome, 0 if not
 */

int co(char *s, int l)
{
	if (*s == *(s + l))
	{
		if (l <= 0)
			return (1);
		else
			return (co(++s, l - 2));
	}
	else
		return (0);
}

/**
 * is_palindrome - check string is a palindrome
 * @s: char array string
 * Return: 1 palindrome, 0 not
 */

int is_palindrome(char *s)
{
	int length;

	length = get(s) - 1;

	return (co(s, --length));
}
