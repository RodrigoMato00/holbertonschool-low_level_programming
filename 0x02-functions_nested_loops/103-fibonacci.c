#include <stdio.h>

/**
 * main - main block
 * Description: Print 4000000 fibonacci numbers, starting with 1 and 2.
 * Numbers must be coma and space separated.
 * Return: 0
 */
int main(void)
{
int i = 1, j = 2, total = 0;
int k;

while (j < 4000000)
{
if (j % 2 == 0)
total += j;

k = j;
j += i;
i = k;
}
printf("%d\n", total);
return (0);
}