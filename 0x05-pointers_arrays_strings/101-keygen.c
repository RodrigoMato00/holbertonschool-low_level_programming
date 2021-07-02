#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - generates random valid passwords for the program 101-crackme
 * Description: generates random valid passwords for the program 101-crackme
 * Return "0"
 */

int main(void)
{
	int co;
	int  ch;
	int  a;

	srand(time(0));
	ch = 2772;
	co = 0;

	while (ch > 122)
	{
		a = (rand() % 100);
		printf("%c", a);
		ch -= a;
		co++;
	}
	printf("%c", ch);
	return (0);
}
