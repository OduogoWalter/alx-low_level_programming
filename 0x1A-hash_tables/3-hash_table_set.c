#include "hash_tables.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


/**
 * hash_table_set - Add or update a key/value pair in the hash table
 * @ht: The hash table
 * @key: The key to be added or updated
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* Check if the hash table and key are valid */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	unsigned long int index;

	/* Calculate the index using the hash function */
	index = key_index((const unsigned char *)key, ht->size);

	/* Create a new node */
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (0);

	/* Duplicate the key and value */
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);

		return (0);

	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);

		return (0);

	}

	/* Handle collisions by adding the new node at the beginning of the list */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);

}
