#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * This function print numbers from 0...9
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int aux;

	for (aux = 0; aux < 10; aux++)
	{
		printf("%d", aux);
	}
	printf("\n");
	return (0);
}
