#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
	int acum = 0;
	int start = 0;
	int n;
	char chars[24] = "abcdefghijklmopqrstuvxyz";
	char pass[50];
	
	srand(time(NULL));
	while (acum < 2772)
	{
		n = rand() % 10;
		pass[start] = chars[n];
		acum = acum + chars[n];
		start++;
	}
	n = 2772 - acum;
	pass[start] = n;
	printf("%s\n", pass);
	return (0);
}
