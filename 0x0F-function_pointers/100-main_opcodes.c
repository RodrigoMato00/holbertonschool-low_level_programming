<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>

/**
 *main - main fuction
 *@argc: numbers parameters
 *argv: array parameters
 *return: return my fuction
 */
int main(int argc, char *argv[])
{
	int i;
	int val;

	if (argc != 2)
	{
		printf("error\n")
			exit(1);
=======

#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry function
 * Description: This function prints the opcodes of its own main function
 * @argc: Number of parameters
 * @argv: Array of parameters
 * Return: 1 if @argc != 2, 2 if atoi of @argv[1] is negative, 0 otherwise
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
>>>>>>> ec544d146eb80bb0688c45347247b8f4fb9128b4
