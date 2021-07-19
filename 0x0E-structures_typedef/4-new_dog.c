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
	char *namec, *ownerc;
	int a = 0, b = 0, c;

	my_dog = malloc(sizeof(struct dog));
	if (my_dog == NULL)
		return (NULL);
	while (*(name + a) != '\0')
		a++;
	while (*(owner + b) != '\0')
		b++;
	namec = malloc(sizeof(char) * (a + 1));
	if (namec == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	ownerc = malloc(sizeof(char) * (b + 1));
	if (ownerc == NULL)
	{
		free(namec);
		free(my_dog);
		return (NULL);
	}
	for (c = 0; c <= a; c++)
	{
		*(namec + c) = *(name + c);
	}
	for (c = 0; c <= b; c++)
	{
		*(ownerc + c) = *(owner + c);
	}
	my_dog->name = namec;
	my_dog->age = age;
	my_dog->owner = ownerc;
	return (my_dog);
}
