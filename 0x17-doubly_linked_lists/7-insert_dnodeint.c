#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to the pointer to the head of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer value for the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node with the given data */
	new_node->n = n;

	/* If the index is 0, the new node becomes the new head */
	if (idx == 0)
	{
		return (insert_at_head(h, new_node));
	}

	 /* Traverse the list to find the node at index-1 */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If the index is greater than the number of nodes, return NULL */
	if (temp == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Update pointers to link the new node at the specified index */
	new_node->prev = temp;
	new_node->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
