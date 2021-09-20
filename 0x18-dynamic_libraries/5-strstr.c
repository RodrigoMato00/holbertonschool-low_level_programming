#include "main.h"

/**
 * _strstr - locates substring
 * Description: Function locates a substring @needle
 * in @haystack
 * @haystack: Pointer contains a string
 * @needle: Pointer contai the substring in @haystack
 * Return: A pointer to the beginning of the located substring
 * in @accept, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int a = 0;
	int b = 0;
	int c;
	int d = 0;

	if (*needle == '\0')
	{
		return (haystack);
	}
	while (*(haystack + a) != '\0')
	{
		b = 0;
		c = a;
		while (*(needle + b) != '\0')
		{
			if (*(needle + b) == *(haystack + c))
			{
				d = 1;
			}
			else
			{
				d = 0;
				break;
			}
			b++;
			c++;
		}
		if (d == 1)
		{
			return (haystack + a);
		}
		a++;
	}
	return (0);
}
