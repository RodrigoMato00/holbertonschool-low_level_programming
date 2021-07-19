#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - Creates a dog
 * Description: This function creates a dog
 * @name: Dog´s name
 * @age: Dog´s age
 * @owner: Dog´s owner
 * Return: A new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *my_dog;
	char *name_cpy, *owner_cpy;
	int i = 0, j = 0, k;

	my_dog = malloc(sizeof(struct dog));
	if (my_dog == NULL)
		return (NULL);
	while (*(name + i) != '\0')
		i++;
	while (*(owner + j) != '\0')
		j++;
	name_cpy = malloc(sizeof(char) * (i + 1));
	if (name_cpy == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	owner_cpy = malloc(sizeof(char) * (j + 1));
	if (owner_cpy == NULL)
	{
		free(name_cpy);
		free(my_dog);
		return (NULL);
	}
	for (k = 0; k <= i; k++)
	{
		*(name_cpy + k) = *(name + k);
	}
	for (k = 0; k <= j; k++)
	{
		*(owner_cpy + k) = *(owner + k);
	}
	my_dog->name = name_cpy;
	my_dog->age = age;
	my_dog->owner = owner_cpy;
	return (my_dog);
}
