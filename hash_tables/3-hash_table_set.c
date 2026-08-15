#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in a hash table.
 * @ht: Pointer to the hash table.
 * @key: The key string (cannot be empty).
 * @value: The value string associated with the key (must be duplicated).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *temp;
	char *value_copy, *key_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	key_copy = strdup(key);
	if (key_copy == NULL)
	{
		free(new_node);
		return (0);
	}

	value_copy = strdup(value);
	if (value_copy == NULL)
	{
		free(key_copy);
		free(new_node);
		return (0);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
