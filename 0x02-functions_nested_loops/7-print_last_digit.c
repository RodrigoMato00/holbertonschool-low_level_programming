#include "holberton.h"

/**
 * print_last_digit - Entry point
 *
 * Description: This function prints the last digit of a number
 *
 * @n: number to get the last digit
 *
 * Return: the last digit of n
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (n > 0)
	{
		_putchar(last_digit + '0');
		return (last_digit);
	}
	else if (n == 0)
	{
		_putchar(n + '0');
		return (n);
	}
	_putchar((last_digit * (-1)) + '0');
	return (last_digit * (-1));
}
