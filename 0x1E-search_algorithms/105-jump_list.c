#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found or list is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value) {
    size_t step = (size_t)sqrt(size);
    size_t i = 0;
    listint_t *node = list;
    listint_t *prev = NULL;

    if (!list)
        return NULL;

    // Jump to the correct block
    while (node && i < size && node->n < value) {
        prev = node;
        for (size_t j = 0; j < step && node && i < size; j++, i++) {
            node = node->next;
        }
        if (prev)
            printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    }

    // Perform linear search in the found block
    if (prev)
        printf("Value found between indexes [%lu] and [%lu]\n", prev->index, node ? node->index : size - 1);
    
    node = prev;
    while (node && node->index <= i && node->n <= value) {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return node;
        node = node->next;
    }

    return NULL;
}
