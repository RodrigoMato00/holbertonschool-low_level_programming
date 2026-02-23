#include <stdio.h>

static void dump_frame(const char *label, int depth)
{
    int local_int = 100 + depth;
    char local_buf[16];
    int *p_local = &local_int;

    local_buf[0] = 'A' + (char)depth;
    local_buf[1] = '\0';

    printf("[%s] depth=%d\n", label, depth);
    printf("  &local_int=%p  p_local=%p  local_int=%d\n",
           (void *)&local_int, (void *)p_local, local_int);
    printf("  local_buf=%p  local_buf[0]=%c\n",
           (void *)local_buf, local_buf[0]);
}

static void walk_stack(int depth, int max_depth)
{
    int marker = depth * 10;
    dump_frame("enter", depth);
    printf("  &marker=%p  marker=%d\n", (void *)&marker, marker);

    if (depth < max_depth)
        walk_stack(depth + 1, max_depth);

    dump_frame("exit", depth);
    printf("  &marker=%p  marker=%d\n", (void *)&marker, marker);
}

int main(void)
{
    printf("stack_example: recursion and stack frames\n");
    walk_stack(0, 3);
    return 0;
}
