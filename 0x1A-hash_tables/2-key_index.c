#include "hash_tables.h"

/**
 *key_index - devulve el indice de la key
 *@key: key de key/value
 *@size: tamano del arrayde la hash table
 *Return: el indice que se debe almacenar key/value en el array en la hash
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
