#include "holberton.h"

/**
 *check - checks number is prime
 *@n: number to test
 *@counter: count numbers
 *
 *Return: 1 if prime, 0 otherwise
 */
int check(int n, int counter)
{
	if (n == counter)
		return (1);
	if ((n % counter) != 0)
	{
		return (check(n, counter + 1));
	}
	else
		return (0);
}

/**
 *is_prime_number - decides integer is prime
 *@n: number
 *
 *Return: 1 prime, 0 otherwise
 */
int is_prime_number(int n)
{
	int counter = 2;

	if (n == 1 || n == -1)
		return (0);
	return (check(n, counter));
}
