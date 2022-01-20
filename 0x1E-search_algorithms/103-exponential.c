#include "search_algos.h"

/**
 *binary_search - searches for a value in a sorted array of integers
 *@array: array of integers
 *@size: size of array
 *@value: value to search for in array of integers
 *Return: index of value or -1 if not found
 **/
int binary_search(int *array, size_t size, int value)
{
	size_t a, med, end;

	if (!array)
		return (-1);

	for (med = 0, end = size - 1; end >= med;)
	{
		printf("Searching in array: ");
		for (a = med; a < end; a++)
			printf("%d, ", array[a]);

		printf("%d\n", array[a]);

		a = med + (end - med) / 2;

		if (array[a] == value)
			return (a);

		else if (array[a] > value)
			end = a - 1;

		else
			med = a + 1;
	}
	return (-1);
}

/**
 *exponential_search - Searches for a value in a sorted array of integers
 *using the exponential search algorithm
 *@array: Pointer to the first element of the array
 *@size: Size of the array
 *@value: Value to search for
 *Return: Index of the value if found, -1 if not found
 **/
int exponential_search(int *array, size_t size, int value)
{
	size_t a, nsize;
	int b;

	a = 1;
	nsize = 0;

	if (!array || !size)
		return (-1);

	while (a < size && array[a] < value)
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		a <<= 1;

	nsize = (a >= size ? size : a + 1) - (a >> 1);
	a >>= 1;

	printf("Value found between indexes [%lu] and [%lu]\n", a, a << 1 >= size ? size - 1 : a << 1);

	b = binary_search(array + a, nsize, value);
	return (b == -1 ? b : b + (int)a);
}