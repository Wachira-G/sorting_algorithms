#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * insertion_sort_list - implements the insertion sort in c
 * @list: the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			swap_nodes(list, temp->prev, temp);
			temp = temp->next;
			current = *list;
		}

		current = current->next;
	}
}


/**
 * swap_nodes - swaps two nodes of a linked list
 * @list: the doubly-linked list
 * @node1: the first node
 * @node2: the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;

	if (node1->next == node2 || node2->next == node1)
	{
		if (node1->next == node2)
		{
			node1->next = node2->next;
			if (node2->next != NULL)
				node2->next->prev = node1;

			node2->prev = node1->prev;
			if (node1->prev != NULL)
				node1->prev->next = node2;
			else
				*list = node2;

			node1->prev = node2;
			node2->next = node1;
		}
		else
		{ /* node2->next == node1 */
			node2->next = node1->next;
			if (node1->next != NULL)
				node1->next->prev = node2;

			node1->prev = node2->prev;
			if (node2->prev != NULL)
				node2->prev->next = node1;
			else
				*list = node1;

			node2->prev = node1;
			node1->next = node2;
		}
	}
	print_list(*list);
}
