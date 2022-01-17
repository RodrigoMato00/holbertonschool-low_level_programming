# 0x1E. C - Search Algorithms #

## 0. Linear search ##
Function that searches for a value in an array of integers using the Linear search algorithm.

-Prototype : int linear_search(int *array, size_t size, int value);
-Where array is a pointer to the first element of the array to search in
-size is the number of elements in array
-And value is the value to search for
-Your function must return the first index where value is located
-If value is not present in array or if array is NULL, your function must return -1
-Every time you compare a value in the array to the value you are searching, you have to print this value (see example below)

 ### Linear search algorithm: ###

 Linear search is also called as sequential search algorithm. It is the simplest searching algorithm. In Linear search, we simply traverse the list completely and match each element of the list with the item whose location is to be found. If the match is found, then the location of the item is returned; otherwise, the algorithm returns NULL.  The time complexity of linear search is O(n).
 The space complexity of linear search is O(1).

 #### Implementation ####

°First, we have to traverse the array elements using a loop.

° in each iteration of for loop, compare the search element with the current array element
    a-If the element matches, then return the index of the corresponding array element.
    b-If the element does not match, then move to the next element.

## 1. Binary search ##

Function that searches for a value in a sorted array of integers using the Binary search algorithm.

-Prototype : int binary_search(int *array, size_t size, int value);
-Where array is a pointer to the first element of the array to search in
-size is the number of elements in array
-And value is the value to search for
Your function must return the index where value is located
-You can assume that array will be sorted in ascending order
-You can assume that value won’t appear more than once in array
-If value is not present in array or -if array is NULL, your function must return -1
-You must print the array being searched every time it changes. (e.g. at the beginning and when you search a subarray) (See example)

### Binary Search Algorithm  ###

Binary search is the search technique that works efficiently on sorted lists. Hence, to search an element into some list using the binary search technique, we must ensure that the list is sorted.
Binary search follows the divide and conquer approach in which the list is divided into two halves, and the item is compared with the middle element of the list. If the match is found then, the location of the middle element is returned. Otherwise, we search into either of the halves depending upon the result produced through the match. The time complexity of binary search is in Best Case O(1) and worst case O(log n). The space complexity of binary search is O(1), as no extra space is used.

#### Implementation ####

° Search a sorted array by repeatedly dividing the search interval in half.
° Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
°Otherwise, narrow it to the upper half.
°Repeatedly check until the value is found or the interval is empty.

## Time complexity ##

Is the time complexity of the algorithm. The time complexity of the algorithm is O(log n) because the algorithm has to make n/2 comparisons in the worst case.

## 2. Big O #0 ##

What is the time complexity (worst case) of a linear search in an array of size n?

## 3. Big O #1 ##

What is the space complexity (worst case) of an iterative linear search algorithm in an array of size n?

## 4. Big O #2 ##

What is the time complexity (worst case) of a binary search in an array of size n?

## 5. Big O #3 ##

what is the space complexity (worst case) of a binary search in an array of size n?

## Space complexity ##

The space complexity is misued for Auxiliary Space at many places. Following are the correct definitions of Auxiliary Space and Space Complexity.
Auxiliary Space is the extra space or temporary space used by an algorithm.
Space Complexity of an algorithm is the total space taken by the algorithm with respect to the input size. Space complexity includes both Auxiliary space and space used by input.

## 6. Big O #4 ##

What is the space complexity of this function / algorithm?

> ```
> int **allocate_map(int n, int m)
>{
>     int **map;
>
>     map = malloc(sizeof(int *) * n);
>     for (size_t i = 0; i < n; i++)
>     {
>          map[i] = malloc(sizeof(int) * m);
>     }
>     return (map);
>}

## 7. Jump search ##

Function that searches for a value in a sorted array of integers using the Jump search algorithm

-Prototype : int jump_search(int *array, size_t size, int value);
-Where array is a pointer to the first element of the array to search in
size is the number of elements in array
-And value is the value to search for
-Your function must return the first index where value is located
-You can assume that array will be sorted in ascending order
If value is not present in array or if array is NULL, your function must return -1
-You have to use the square root of the size of the array as the jump step.
-You can use the sqrt() function included in <math.h> (don’t forget to compile with -lm)
-Every time you compare a value in the array to the value you are searching for, you have to print this value (see example)

> ```
>wilfried@0x1E-search_algorithms$ cat 100-main.c
>#include <stdio.h>
>#include <stdlib.h>
>#include "search_algos.h"
>
>/**
> * main - Entry point
> *
> * Return: Always EXIT_SUCCESS
> */
>int main(void)
>{
>    int array[] = {
>        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
>    };
>    size_t size = sizeof(array) / sizeof(array[0]);
>
>   printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
>    printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
>    printf("Found %d at index: %d\n", 999, jump_search(array, size, 999));
>    return (EXIT_SUCCESS);
>}
>wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 100-main.c 100-jump.c -lm -o 100-jump
>wilfried@0x1E-search_algorithms$ ./100-jump
>Value checked array[0] = [0]
>Value checked array[3] = [3]
>Value found between indexes [3] and [6]
>Value checked array[3] = [3]
>Value checked array[4] = [4]
>Value checked array[5] = [5]
>Value checked array[6] = [6]
>Found 6 at index: 6
>
>Value checked array[0] = [0]
>Value found between indexes [0] and [3]
>Value checked array[0] = [0]
>Value checked array[1] = [1]
>Found 1 at index: 1
>
>Value checked array[0] = [0]
>Value checked array[3] = [3]
>Value checked array[6] = [6]
>Value checked array[9] = [9]
>Value found between indexes [9] and [12]
>Value checked array[9] = [9]
>Found 999 at index: -1

### Jump Search Algorithm ###

Jump Search is a searching algorithm for sorted arrays. The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements one by one. The time complexity of jump search is O(√(n)). The space complexity of jump search is O(1).

### Implementation ###

#### Iterative Implementation ####

First off, we've calculated the block size. Generally, a square root of the array's length is a good size to choose. This is further explained in the Big-O Analysis section. Searching through a block like this, in the end, will also be cheap for an algorithm like Linear Search.

Since the array is sorted, if our target element's value is greater than the value of the current element, then the target element surely cannot be inside the current block. So we jump to the next block and compare the target element with the new block’s last index element value.

his jump is repeated until the block that contains the target element is found.

If the target element is no longer greater than the value of the last element in a block, then it has to be inside the block if it exists at all.

So we will find the accurate position of the target element using Linear Search

If we reach the end of the array without finding a block that contains our target element - it's not present in the array and we return -1 to signify that.

#### Recursive Implementation ####

Recursively performing a Jump Search works in the same way. We just call the method recursively instead of having a while loop.

We need the use of an initializer method to make some initial calculations. Namely, the optimum block size and the last index of the very first block.

Thereafter, for as long as our target element is greater than the current block’s last index element value, we recursively call Jump Search method passing the parameters of the subsequent block to it.

This recursion ends once the block containing the target element was found, or if the array end was reached eventually

In case such a target block was found, we perform a Linear Search on it to find the position of the target element.

## 8. Big O #5 ##

What is the time complexity (average case) of a jump search in an array of size n, using step = sqrt(n)?

## 9. Interpolation search ##

Function that searches for a value in a sorted array of integers using the Interpolation search algorithm

-Prototype : int interpolation_search(int *array, size_t size, int value);
-Where array is a pointer to the first element of the array to search in
size is the number of elements in array
-And value is the value to search for
-Your function must return the first index where value is located
-You can assume that array will be sorted in ascending order
-If value is not present in array or if array is NULL, your function must return -1
-To determine the probe position, you can use : size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]))
-Every time you compare a value in the array to the value you are searching, you have to print this value (see example below)

>```
>wilfried@0x1E-search_algorithms$ cat 102-main.c
>#include <stdio.h>
>#include <stdlib.h>
>#include "search_algos.h"
>
>/**
>* main - Entry point
> *
> * Return: Always EXIT_SUCCESS
> */
>int main(void)
>{
>    int array[] = {
>        0, 0, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9
>    };
>    size_t size = sizeof(array) / sizeof(array[0]);
>
>    printf("Found %d at index: %d\n\n", 3, interpolation_search(array, size, 3));
>    printf("Found %d at index: %d\n\n", 7, interpolation_search(array, size, 7));
>    printf("Found %d at index: %d\n", 999, interpolation_search(array, size, 999));
>    return (EXIT_SUCCESS);
>}
>wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 102-main.c 102-interpolation.c -o 102-interpolation
>wilfried@0x1E-search_algorithms$ ./102-interpolation
>Value checked array[6] = [2]
>Value checked array[7] = [3]
>Found 3 at index: 7
>
>Value checked array[14] = [7]
>Found 7 at index: 14
>
>Value checked array[2109] is out of range
>Found 999 at index: -1

### Interpolation Search Algorithm ###

Interpolation Search is a searching algorithm for sorted arrays. The basic idea is to check fewer elements (than linear search) by interpolating between two elements. The time complexity of interpolation search is O(log(n)). The space complexity of interpolation search is O(1).

#### Implementation ####

Rest of the Interpolation algorithm is the same except the above partition logic.
°In a loop, calculate the value of “pos” using the probe position formula.
°If it is a match, return the index of the item, and exit.
°If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
°Repeat until a match is found or the sub-array reduces to zero.
Because the sub-array reduces to zero, the search terminates.

## 10. Exponential search ##

function that searches for a value in a sorted array of integers using the Exponential search algorithm

Prototype : int exponential_search(int *array, size_t size, int value);
Where array is a pointer to the first element of the array to search in
size is the number of elements in array
And value is the value to search for
Your function must return the first index where value is located
You can assume that array will be sorted in ascending order
If value is not present in array or if array is NULL, your function must return -1
You have to use powers of 2 as exponential ranges to search in your array
Every time you compare a value in the array to the value you are searching for, you have to print this value (See example)
Once you’ve found the good range, you need to use a binary search:
Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)

>```
>wilfried@0x1E-search_algorithms$ cat 103-main.c
>#include <stdio.h>
>#include <stdlib.h>
>#include "search_algos.h"
>
>/**
> * main - Entry point
> *
> * Return: Always EXIT_SUCCESS
> */
>int main(void)
>{
>    int array[] = {
>        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
>    };
>    size_t size = sizeof(array) / sizeof(array[0]);
>
>    printf("Found %d at index: %d\n\n", 62, exponential_search(array, size, 62));
>    printf("Found %d at index: %d\n\n", 3, exponential_search(array, size, 3));
>    printf("Found %d at index: %d\n", 999, exponential_search(array, size, 999));
>    return (EXIT_SUCCESS);
>}
>wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 103-main.c 103-exponential.c -o 103-exponential
>wilfried@0x1E-search_algorithms$ ./103-exponential
>Value checked array[1] = [1]
>Value checked array[2] = [2]
>Value checked array[4] = [4]
>Value checked array[8] = [18]
>Value found between indexes [8] and [15]
>Searching in array: 18, 19, 23, 54, 61, 62, 76, 99
>Searching in array: 61, 62, 76, 99
>Found 62 at index: 13
>
>Value checked array[1] = [1]
>Value checked array[2] = [2]
>Value found between indexes [2] and [4]
>Searching in array: 2, 3, 4
>Found 3 at index: 3
>
>Value checked array[1] = [1]
>Value checked array[2] = [2]
>Value checked array[4] = [4]
>Value checked array[8] = [18]
>Value found between indexes [8] and [15]
>Searching in array: 18, 19, 23, 54, 61, 62, 76, 99
>Searching in array: 61, 62, 76, 99
>Searching in array: 76, 99
>Searching in array: 99
>Found 999 at index: -1

### Exponential Search Algorithm ###

Exponential search, also known as doubling search or finger search, is an algorithm created for searching elements in huge sized arrays. It is a two-step process. First, the algorithm tries to find the range (L, R) in which the target element is present and then uses binary search inside this range to find the target’s exact location.
It is named exponential search because it finds the range holding element by searching for the first exponent k for which element at index pow(2,k) is greater than the target. Although its name is exponential search, the time complexity of this algorithm is logarithmic. It is very useful when arrays are of infinite size and converges to a solution much faster than binary search. The time complexity of exponential search is O(log(n)). The space complexity of exponential search is O(1).

#### Implementation ####

Have an unsorted array **array[]** containing **n** elements, and we want to find an element **X**.

°Check if the first element itself is the target element i.e. **A[0] == X.**
°Initialize **i** as **1**.
°While **i < n** and **array[i] <= X** do the following:
°Increment **i** in powers of **2** i.e. **i = i*2**.
°Apply binary search on the range **i/2** to **min(i,n-1)**.

## 11. Adbanced Binary Search ##

You may have noticed that the basic binary search does not necessarily return the index of the first value in the array (if this value appears more than once in the array). In this exercise, you’ll have to solve this problem.

Write a function that searches for a value in a sorted array of integers.

-Prototype : int advanced_binary(int *array, size_t size, int value);
-Where array is a pointer to the first element of the array to search in
size is the number of elements in array
-And value is the value to search for
-Your function must return the index where value is located
-You can assume that array will be sorted in ascending order
-If value is not present in array or if array is NULL, your function must return -1
-Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)
-You have to use recursion. You may only use one loop (while, for, do while, etc.) in order to print the array
-wilfried@0x1E-search_algorithms$ cat 104-main.c
>```
>#include <stdio.h>
>#include <stdlib.h>
>#include "search_algos.h"
>
>/**
> * main - Entry point
> *
> * Return: Always EXIT_SUCCESS
> */
>int main(void)
>{
>    int array[] = {
>        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
>    };
>    size_t size = sizeof(array) / sizeof(array[0]);
>
>    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
>    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
>    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
>    return (EXIT_SUCCESS);
>}
>wilfried@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 104-main.c 104-advanced_binary.c -o 104-advanced_binary
>wilfried@0x1E-search_algorithms$ ./104-advanced_binary
>Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
>Searching in array: 6, 6, 7, 8, 9
>Searching in array: 8, 9
>Found 8 at index: 8
>
>Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
>Searching in array: 0, 1, 2, 5, 5
>Searching in array: 5, 5
>Found 5 at index: 3
>
>Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
>Searching in array: 6, 6, 7, 8, 9
>Searching in array: 8, 9
>Searching in array: 9
>Found 999 at index: -1
