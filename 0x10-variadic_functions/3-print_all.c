#include "variadic_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printchar - print char type element from va_list
 * @list: va_list passed to function
 */
void _printchar(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * _printstr - print string element from va_list
 * @list: va_list passed to function
 */
void _printstr(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
 * _printfloat - print float type element from va_list
 * @list: va_list passed to function
 */
void _printfloat(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * _printint - print int type element from va_list
 * @list: va_list passed to function
 */
void _printint(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_all - print anything passed if char, int, float, or string.
 * @format: string of formats to use and print
 */
void print_all(const char * const format, ...)
{
	va_list args_list;
	int i = 0;
	char op;
	char *s;

	va_start(args_list, format);
	while (format && *(format + i) != '\0')
	{
		op = *(format + i);
		switch (op)
		{
		case 'c':
			printf("%c", va_arg(args_list, int));
			break;
		case 'i':
			printf("%d", va_arg(args_list, int));
			break;
		case 'f':
			printf("%f", va_arg(args_list, double));
			break;
		case 's':
			s = va_arg(args_list, char *);
			if (!s)
				s = "(nil)";
			printf("%s", s);
			break;
		}
		if ((op == 'c' || op == 'i' || op == 'f' || op == 's') && *(format + i + 1))
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(args_list);
}
