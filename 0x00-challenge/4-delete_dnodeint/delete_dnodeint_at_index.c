#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;

	/* traverse to the index node */
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	/* if index is out of range */
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	else if (index == 0)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;

		/* if the next node is not the end node */
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		/* fix the link b/w previous node and the next node */
		(*head)->prev->next = (*head)->next;
		free(*head);
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		*head = saved_head;
	}
	return (1);
}
