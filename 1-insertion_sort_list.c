#include "sort.h"

/**
 * swapNodes - swaps 2 nodes in a doubly linked list
 * @n1: first node
 * @n2: second node
 */
void swapNodes(listint_t *n1, listint_t *n2)
{
	if (n1->prev != NULL)
		n1->prev->next = n2;
	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && curr->n < prev->n)
		{
			if (prev->prev == NULL)
				*list = curr;
			swapNodes(prev, curr);
			print_list(*list);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}
