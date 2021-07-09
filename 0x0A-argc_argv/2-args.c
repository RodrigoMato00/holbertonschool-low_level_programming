#include "holberton.h"
#include <stdio.h>

/**
 * main - main entry
 *@argc: number of arguments
 *@argv: string with arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;

	(void)argv;
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
