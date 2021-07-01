#include "holberton.h"

/**
 * cap_string - Capitalize a string
 * Description: This function capitalize a string. Separators of words:
 * Space, tabulation, new line, ',', ';', '.', '!', '?', '"', '(', ')'
 * '{', '}'
 * @s: String to capitalize
 * Return: @s capitalized
 */
char *cap_string(char *s)
{
	int c = 0;
	int next_cap = 0;

	while (*(s + c) != '\0')
	{
		if (
			(*(s + c - 1) == ' ') || (*(s + c - 1) == '\t') ||
			(*(s + c - 1) == '\n') || (*(s + c - 1) == ',') ||
			(*(s + c - 1) == ';') || (*(s + c - 1) == '.') ||
			(*(s + c - 1) == '!') || (*(s + c - 1) == '?') ||
			(*(s + c - 1) == '"') || (*(s + c - 1) == '(') ||
			(*(s + c - 1) == ')') || (*(s + c - 1) == '{') ||
			(*(s + c - 1) == '}') || c == 0
			)
		{
			next_cap = 1;
		}
		if (next_cap == 1 && *(s + c) >= 97 && *(s + c) <= 122)
		{
			*(s + c) = *(s + c) - 32;
		}
		next_cap = 0;
		c++;
	}
	return (s);
}
