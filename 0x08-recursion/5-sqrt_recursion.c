#include "holberton.h"
/**
 *comp - function that returns the power of number
 *@n: original number
 *@y: counter to compare multiplication
 *
 *Return: square root
 */
int comp(int n, int y)
{
	if (y * y == n)
	{
		return (y);
	}
	else if (y * y > n)
	{
		return (-1);

	}
	return (comp(n, y + 1));
}
/**
 *_sqrt_recursion - function that returns the power of number
 *@n: number
 *Return: the natural square root
 */
int _sqrt_recursion(int n)
{
	return (comp(n, 1));
}
