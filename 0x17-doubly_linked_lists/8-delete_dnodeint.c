#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to the pointer to the head of the list.
 * @index: Index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head, *prev_node;
	unsigned int i = 0;

	/* If the list is empty, return -1 */
	if (*head == NULL)
		return (-1);

	/* If the node to be deleted is the head */
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Traverse the list to find the node at index */
	while (temp != NULL && i < index)
	{
		prev_node = temp;
		temp = temp->next;
		i++;
	}

	/* If the index is greater than the number of nodes, return -1 */
	if (temp == NULL)
		return (-1);

	/* Update pointers to skip the node to be deleted */
	prev_node->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = prev_node;

	free(temp);
	return (-1);
}
