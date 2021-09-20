#include "main.h"

/**
 * _strncpy - Copy a string
 * Description: This function copies a string from 0 to @n bytes
 * @dest: String where gonna copy
 * @src: String to copy into @dest
 * @n: Number of bytes to copy
 * Return: @n bytes of @src
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(dest + i) != '\0')
	{
		if (*src != '\0')
			*(dest + i) = *src++;
		else
			*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
