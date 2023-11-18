#include "sort.h"

void insertion_sort_list(listint_t **list);
void insertion_sort_list1(listint_t **list);

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


void insertion_sort_list1(listint_t **list)
{
	listint_t *node, *prev, *next, *tmp;

	if (!list || !*list || !(*list)->next)
		return;
	next = (*list)->next;
	while (next)
	{
		node = next;
		prev = next->prev;
		while (prev)
		{
			if (node->n >= prev->n)
			{
				next = next->next;
				if (node->prev != prev)
				{
					node->prev->next = node->next;
					if (node->next)
						node->next->prev = node->prev;
					tmp = prev->next;
					prev->next = node;
					node->prev = prev;
					node->next = tmp;
					if (tmp)
						tmp->prev = node;
					print_list(*list);
				}
				break;
			}
			prev = prev->prev;
			if (!prev)
			{
				next = next->next;
				node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = *list;
				(*list)->prev = node;
				node->prev = NULL;
				*list = node;
				print_list(*list);
			}
		}
	}
}
