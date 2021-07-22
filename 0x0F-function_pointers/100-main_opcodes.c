#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry function
 * Description: This function prints the opcodes
 * @argc: Number of parameters
 * @argv: Array of parameters
 * Return: retur of the main fuction
*/
int main(int argc, char *argv[])
{
	int i, value;

	if (argc != 2)

	{
		printf("Error\n");
		exit(1);
	}

	value = atoi(argv[1]);

	if (value < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < value; i++)
	{
		printf("%02hhx", *((unsigned char *) main + i));
		if (i < value - 1)
			printf(" ");
		else
			printf("\n");
	}
	return (0);
}
