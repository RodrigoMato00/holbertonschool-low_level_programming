#include "search_algos.h"

/**
 *linear_search - searches for a value in a sorted array of integers
 *@array: array of integers
 *@size: size of array
 *@value: value to search for in array of integers
 *return: index of value or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
    size_t a;

    if (!array)
        return (-1);

    for (a = 0; a < size; a++)
    {
        printf ("Value checked array[%li] = [%i]\n", a, array[a]);

        if (array[a] == value)
            return (a);
    }
    return (-1);
}