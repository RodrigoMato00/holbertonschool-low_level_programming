#include "search_algos.h"

/**
 * interpolation_search - searches for an integer in a sorted array of integers
 * using interpolation search
 * @array: pointer to the first element of the array
 * @size: size of the array
 * @value: value to search for
 * Return: index of the element or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{

	size_t left, right, pos;

	if (!array)
		return (-1);

	for (left = 0, right = size - 1; left <= right;)
	{
		pos = left + (((double)(right - left) / (array[right] - array[left])));

		if (pos <= size)
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		else
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}
		if (array[pos] > value)
			right = pos - 1;
		if (array[pos] < value)
			left = pos + 1;
		else if (array[pos] == value)
			return (pos);
		else
			return (pos);
	}
	return (-1);
}