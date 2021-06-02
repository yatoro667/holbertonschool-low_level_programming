#include "hash_tables.h"

/**
 * hast_table_set - adds element to hash table
 * @ht: hash table
 * @key: key
 * @value: value associated with key
 * Return: 1 if succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *h_node;
	unsigned long int idx = 0;

	if (key == NULL || value == NULL || ht == NULL || (strcmp(key, "") == 0))
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	h_node = ht->array[idx];

	while (h_node)
	{
		if (strcmp(h_node->key, key))
		{
			free(h_node->value);
			h_node->value = strdup(value);
		}
		h_node = h_node->next;
	}

		
	new_node = malloc(sizeof(hash_node_t *));

	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
