#include "sort.h"

void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - Sorting algo
 * @list: to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *prev, *next;

	if (!list || !*list || !(*list)->next)
		return;
	next = (*list)->next;
	while (next)
	{
		node = next;
		prev = next->prev;
		next = next->next;
		while (prev && node->n < prev->n)
		{
			prev->next = node->next;
			if (node->next)
				node->next->prev = prev;
			node->next = prev;
			node->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = node;
			else
				*list = node;
			prev->prev = node;
			prev = node->prev;
			print_list(*list);
		}
	}
}
