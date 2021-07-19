#ifndef STRUCTFILE
#define STRUCTFILE

/**
 *struct dog - dog structure
 *@name: name of the dog
 *@age: the age of the dog
 *@owner: the owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * init_dog - Initializatio of dog
 * Description: initializes a dog
 * @d: Dog structure
 * @name: Dog name
 * @age: Dog age
 * @owner: Dog owner
 * Return:
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - Print dog
 * Description: This function prints a dog info
 * @d: Dog structure
 * Return:
 */
void print_dog(struct dog *d);

typedef struct dog dog_t;

/**
 * new_dog - Create a dog
 * Description: create a dog
 * @name: Dog name
 * @age: Dog age
 * @owner: Dog owner
 * Return: A new dog
 */
dog_t *new_dog(char *name, float age, char *owner);

/**
 * free_dog - Frees a dog
 * Description: This function frees a dog
 * @d: Dog structure
 * Return:
 */
void free_dog(dog_t *d);

#endif
