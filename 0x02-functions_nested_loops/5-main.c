#include "holberton.h"

/**
 * print_sign - Entry point
 *
 * Description: This function print the sign of a number
 *
 * @n: number to discover the sign
 *
 * Return: 1 if n is positive, 0 is zero, -1 if is less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	_putchar('-');
	return (-1);
}
