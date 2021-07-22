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
