#include "search_algos.h"

/**
 *jump_search - searches for a value in a sorted array of integers
 *@array: array of integers
 *@size: size of array
 *@value: value to search for in array of integers
 *Return: index of value or -1 if not found
 **/
int jump_search(int *array, size_t size, int value)
{
	size_t a, pos;

	if (!array || array[0] > value)
		return (-1);

	a = sqrt(size);
	pos = 0;

	printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
	/*print value checked array[0] = [0]*/

	while (pos + a < size && value > array[pos + a])
	{
		printf("Value checked array[%lu] = [%d]\n", pos + a, array[a + pos]);
		pos += a;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", pos, a + pos);

	while (size > pos)
	{
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		pos++;
	}
	return (-1);
}
