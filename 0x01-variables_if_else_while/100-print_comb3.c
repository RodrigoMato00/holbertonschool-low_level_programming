/**
 * main - Entry point
 *
 * This function prints all possible different combinations of two digits
 *
 * Return: Always 0 (success)
 */
int main(void)
{
int aux;
int aux2;

for (aux = 0; aux < 10; aux++)
{
for (aux2 = 0; aux2 < 10; aux2++)
{
if (aux != aux2 && aux < aux2)
{
putchar((aux % 10) + '0');
putchar((aux2 % 10) + '0');
if (aux != 8 || aux2 != 9)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');
return (0);
}
