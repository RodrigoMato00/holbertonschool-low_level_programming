#include <stdarg.h>
#include <stdio.h>

 /**
  * print_all - Prints all
  * Description: This is a variadic function prints all
  * @format: Format of data
  * Return:
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
