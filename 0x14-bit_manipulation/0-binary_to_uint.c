#include "main.h"

/**
 *binary_to_uint - converts a binary number to an unsigned int
 *@b: string
 *Return: number converted
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int t;
	unsigned int u;
	int len;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	for (u = 1, t = 0, len--; len >= 0; len--, u *= 2)
	{
		if (b[len] == '1')
			t += u;
	}
	return (t);
}
