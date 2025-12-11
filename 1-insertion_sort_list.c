#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion sort algorithm (by swapping nodes)
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}

		current = next_node;
	}
}
