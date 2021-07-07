#include "holberton.h"

/**
 *factorial - return factorial
 *@n: int number
 *Return: factortial number
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n < 2)
	{
		return (n);
	}
	else
		return (n * factorial(n - 1));
}
