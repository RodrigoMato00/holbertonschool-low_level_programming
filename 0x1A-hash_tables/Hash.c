{
	unsigned long int index;
	hash_node_t *new;
	hash_node_t *tmp;

	if (key == NULL || value == NULL || ht == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];


	while (tmp)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}


	new = malloc(sizeof(hash_node_t));

	if (new == NULL)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);
	new->next = NULL;

	if (ht->array[index] == NULL)
	{
		ht->array[index] = new;
		return (1);
	}

	tmp = ht->array[index];
	new->next = tmp;
	ht->array[index] = new;
	return (1);
}
