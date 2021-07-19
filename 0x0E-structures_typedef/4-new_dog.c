#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - Creates a dog
 * Description: creates a dog
 * @name: Dog name
 * @age: Dog age
 * @owner: Dog owner
 * Return: A new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *my_dog;
	int a, b, c;
	char *n, *o;

	my_dog = malloc(sizeof(struct dog));
	if (my_dog == NULL)
		return (NULL);

	for (a = 0; name[a] != '\0'; a++)
		;
	for (b = 0; owner[b] != '\0'; b++)
		;

	n = malloc(sizeof(char) * b + 1);
	if (n == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	o = malloc(sizeof(char) * a + 1);
	if (o == NULL)
	{
		free(n);
		free(my_dog);
		return (NULL);
	}
	for (c = 0; c <= a; c++)
		n[c] = name[c];
	for (c = 0; c <= b; c++)
		o[c] = owner[c];

	my_dog->name = n;
	my_dog->age = age;
	my_dog->owner = o;

	return (my_dog);
}
