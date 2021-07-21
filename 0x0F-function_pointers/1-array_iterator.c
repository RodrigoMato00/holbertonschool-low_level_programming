#include "function_pointers.h"

/**
 *array_iterator - interators of array
 *@array: array of integers
 *@action: fuction pointer
 *@size: size of array
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t a;

	if (array && action && size > 0)

		for (a = 0; a < size; a++)
			action(array[a]);
}
