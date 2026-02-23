#include <stdio.h>
#include <stdlib.h>

static int *make_numbers(int n)
{
    int i = 0;
    int *arr = NULL;

    if (n <= 0)
        return NULL;

    arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr)
        return NULL;

    for (i = 0; i < n; i++)
        arr[i] = i * 11;

    return arr;
}

int main(void)
{
    int *a = NULL;
    int *b = NULL;
    int n = 5;

    printf("aliasing_example: aliasing and use-after-free (Valgrind should report it)\n");

    a = make_numbers(n);
    if (!a)
        return 1;

    b = a;

    printf("  a=%p b=%p a[2]=%d b[2]=%d\n", (void *)a, (void *)b, a[2], b[2]);

    free(a);

    printf("  after free(a): b=%p (dangling)\n", (void *)b);

    printf("  reading b[2]=%d\n", b[2]);

    b[3] = 1234;
    printf("  wrote b[3]=%d\n", b[3]);

    return 0;
}
