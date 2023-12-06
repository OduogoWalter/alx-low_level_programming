#include "hash_tables.h"

/**
 * key_index - Get the index of a key in the hash table array
 * @key: The key to be hashed
 * @size: The size of the hash table array
 *
 * Return: The index at which the key should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
