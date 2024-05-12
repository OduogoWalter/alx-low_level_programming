#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found or head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value) {
    skiplist_t *node = list;
    skiplist_t *express = NULL;

    if (!list)
        return NULL;

    // Use the express lane to get closer to the target value
    while (node && node->express && node->express->n < value) {
        printf("Value checked at index [%lu] = [%d]\n", node->express->index, node->express->n);
        node = node->express;
    }

    if (!node->express)
        express = node;
    while (express && express->next)
        express = express->next;

    // Announce the range where the value could be
    printf("Value found between indexes [%lu] and [%lu]\n", node->index, express->index);

    // Perform a linear search in the range
    while (node && node->index <= express->index) {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return node;
        node = node->next;
    }

    return NULL;
}
