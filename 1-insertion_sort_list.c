#include "sort.h"

void swap_node(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * insertion_sort_list - implements the insertion sort in c
 * @list: the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *temp2 = NULL;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;
	while (temp != NULL)
	{
		if (temp->next)
			temp2 = temp->next;
		while (temp2 && temp->n > temp2->n)
			swap_node(list, temp, temp2);
		temp = temp->next;
	}
}


/**
 * swap_node - swaps two nodes of a linked list
 * @list: the doubly-linked list
 * @node1: the first node
 * @node2: the second node
 */
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp = NULL;

	if (node1 == NULL || node2 == NULL ||
	node1->next != node2 || node2->prev != node1)
	return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	temp = node2->next;
	node1->next = node2->next;
	node2->next = temp;

	temp = node1->prev;
	node1->prev = node2;
	node2->prev = temp;
}
