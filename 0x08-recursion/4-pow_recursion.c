#include "holberton.h"

/**
 *_pow_recursion - return value x raised to power of y
 *@x: number
 *@y: power
 *Return: x of power y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else if (y == 1)
		return (x);

	return (x * _pow_recursion(x, y - 1));
}
