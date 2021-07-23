#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 *print_all - function that prints anything
 *@format: this is a format
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int n = 0;
	int i = 0;
	char *comma = ", ";
	char *c;

	va_start(list, format);

	while (format && format[i])
		i++;

	while (format && format[n])
	{
		if (n == (i - 1))
		{
			comma = "";
		}
		switch (format[n])
		{
		case 'c':
			printf("%c%s", va_arg(list, int), comma);
			break;
		case 'i':
			printf("%d%s", va_arg(list, int), comma);
			break;
		case 'f':
			printf("%f%s", va_arg(list, double), comma);
			break;
		case 's':
			c = va_arg(list, char *);
			if (c == NULL)
				c = "(nil)";
					printf("%s%s", c, comma);
			break;
		}
		n++;
	}
	printf("\n");
	va_end(list);
}
