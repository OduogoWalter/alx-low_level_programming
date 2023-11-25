#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @n: Integer value for the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node with the given data */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, the new node becomes the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the last node */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* Update pointers to link the new node at the end */
	new_node->prev = temp;
	temp->next = new_node;

	return (new_node);
}
