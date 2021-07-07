#include "holberton.h"

/**
 *_puts_recursion - print a string
 *@s is a string
 */
void _puts_recursion(char *s)
{
	if (*s == '\n')
		_putchar('\n');
	else
	{
		_putchar(*s);
		_puts_recursion(++s);
	}
}
