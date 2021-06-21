#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * This function print the alphabet a...z
 *
 * Return: 0
 */
int main(void)
{
int aux;

for (aux = 0; aux < 10; aux++)
{
putchar((aux % 10) + '0');
if (aux < 9)
{
putchar(',');
putchar(' ');
}
}
putchar('\n');
return (0);
}
