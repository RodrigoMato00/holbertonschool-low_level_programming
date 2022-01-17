#include "search_algos.h"

/**
 *linear_search - searches for a value in a sorted array of integers
 *@array: array of integers
 *@size: size of array
 *@value: value to search for in array of integers
 *return: index of value or -1 if not found
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