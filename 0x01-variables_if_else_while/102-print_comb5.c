#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * prints all possible combinations of two two-digit numbers.
 *The numbers should range from 0 to 99
 *The two numbers should be separated by a space
 *All numbers should be printed with two digits. 1 should be printed as 01
 *The combination of numbers must be separated by comma, followed by a space
 *The combinations of numbers should be printed in ascending order
 *00 01 and 01 00 are considered as the same combination of the numbers 0 and 1
 *
 * Return: 0
 */
int main(void)
{
int aux;
int aux2;

for (aux = 0; aux < 100; aux++)
{
for (aux2 = 0; aux2 < 100; aux2++)
{
if (aux != aux2 && aux < aux2)
{
putchar(((aux / 10) % 10) + '0');
putchar((aux % 10) + '0');
putchar(' ');
putchar(((aux2 / 10) % 10) + '0');
putchar((aux2 % 10) + '0');
if (aux != 98 || aux2 != 99)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');
}
