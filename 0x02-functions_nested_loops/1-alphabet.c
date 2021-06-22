#include "holberton.h"

/**
 *print_alphabet - this fuction print alphabet using the fuction _putchar
 *Description: this fuction print alphabet using the fuction _putchar
 *Return 0
 */
void print_alphabet(void)
{
char c = 'a';
while (c <= 'z')
{
_putchar(c);
c++;
}
_putchar('\n');
}
