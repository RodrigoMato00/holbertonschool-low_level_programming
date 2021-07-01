#include "holberton.h"

/**
 * leet - Capitalize a string
 * Description: This function encodes a string into 1337
 * a and A replaced by 4
 * e and E replaces by 3
 * o and O replaces by 0
 * t and t replaces by 7
 * l and L replaces by 1
 * @s: String to capitalize
 * Return: @s encoded
 */
char *leet(char *s)
{
	char let[] = "aAeEoOtTlL";
	char num[] = "4433007711";
	int c = 0;
	int let_c;

	while (*(s + c) != '\0')
	{
		let_c = 0;
		while (let[let_c] != '\0')
		{
			if (*(s + c) == let[let_c])
			{
				*(s + c) = num[let_c];
			}
			let_c++;
		}
		c++;
	}
	return (s);
}
