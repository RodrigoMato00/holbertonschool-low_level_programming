#include "holberton.h"
/**
 *main - print "holberton " include followed be a new line
 *Description: you are not allowed to include a standar libraries
 *Return: 0
 */
int  main(void)
{
char holberton[] = "Holberton";
int i = 0;
while (holberton[i] != '\0')
{
_putchar(holberton[i]);
i++;
}
_putchar('\n');
return (0);
}
