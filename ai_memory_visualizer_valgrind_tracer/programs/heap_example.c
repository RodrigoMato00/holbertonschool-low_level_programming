#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
    char *name;
    int age;
} Person;

static Person *person_new(const char *name, int age)
{
    size_t i = 0;
    size_t len = 0;
    Person *p = (Person *)malloc(sizeof(Person));
    if (!p)
        return NULL;

    while (name[len] != '\0')
        len++;

    p->name = (char *)malloc(len + 1);
    if (!p->name)
    {
        free(p);
        return NULL;
    }

    for (i = 0; i < len; i++)
        p->name[i] = name[i];
    p->name[len] = '\0';

    p->age = age;
    return p;
}

static void person_free_partial(Person *p)
{
    if (!p)
        return;

    free(p);
}

int main(void)
{
    Person *alice = NULL;
    Person *bob = NULL;

    printf("heap_example: allocations and a deliberate leak\n");

    alice = person_new("Alice", 30);
    bob = person_new("Bob", 41);

    if (!alice || !bob)
    {
        if (alice)
            person_free_partial(alice);
        if (bob)
            person_free_partial(bob);
        return 1;
    }

    printf("  alice=%p name=%p age=%d\n", (void *)alice, (void *)alice->name, alice->age);
    printf("  bob=%p name=%p age=%d\n", (void *)bob, (void *)bob->name, bob->age);

    free(bob->name);
    free(bob);

    person_free_partial(alice);

    return 0;
}
