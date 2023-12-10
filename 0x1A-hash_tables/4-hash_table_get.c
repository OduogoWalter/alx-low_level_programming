#include "hash_tables.h"

/**
 * hash_table_get - Retrieve a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to search for
 *
 * Return - The value assocaited with the element, or NULL if the key is not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}
