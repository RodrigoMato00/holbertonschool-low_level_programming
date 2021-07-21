#include "function_pointers.h"

/**
 *print_name - print name the fuction pointer
 *@name: char string
 *@f: fuction pointer
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
