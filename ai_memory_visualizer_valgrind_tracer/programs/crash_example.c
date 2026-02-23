#include <stdio.h>
#include <stdlib.h>

static int *allocate_numbers(int n)
{
    int *arr = NULL;
    int i = 0;

    if (n <= 0)
        return NULL;

    arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr)
        return NULL;

    for (i = 0; i < n; i++)
        arr[i] = (i + 1) * 7;

    return arr;
}

int main(void)
{
    int *nums = NULL;
    int n = 0;

    printf("crash_example: deterministic NULL dereference (segmentation fault)\n");
    printf("  requesting n=%d\n", n);

    nums = allocate_numbers(n);

    nums[0] = 42;

    printf("  nums[0]=%d\n", nums[0]);

    free(nums);
    return 0;
}
