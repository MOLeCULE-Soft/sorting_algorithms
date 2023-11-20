#include "sort.h"

void swap(listint_t **head, listint_t **tail, listint_t *a, listint_t *b);

/**
 * cocktail_sort_list - Sorting Aglo
 * @list: to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	bool repeat = true, first = true;
	listint_t *tail, *forward, *backward;

	if (!list || !*list || !(*list)->next)
		return;

	forward = *list;
	while (repeat)
	{
		repeat = false;
		while (forward && forward->next)
		{
			if (!forward->next->next && first)
			{
				tail = forward->next;
				first = false;
			}
			if (forward->n > forward->next->n)
			{
				swap(list, &tail, forward, forward->next);
				backward = forward->prev;
				repeat = true;
				print_list(*list);
				continue;
			}
			forward = forward->next;
		}
		while (backward && backward->prev)
		{
			if (backward->n < backward->prev->n)
			{
				swap(list, &tail, backward->prev, backward);
				forward = backward->next;
				repeat = true;
				print_list(*list);
				continue;
			}
			backward = backward->prev;
		}
	}
}

/**
 * swap - two linked lsit nodes
 * @head: of list
 * @tail: of list
 * @a: a node
 * @b: another node
*/
void swap(listint_t **head, listint_t **tail, listint_t *a, listint_t *b)
{
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	else
		*tail = a;
	b->next = a;
	b->prev = a->prev;
	if (b->prev)
		b->prev->next = b;
	else
		*head = b;
	a->prev = b;
}
