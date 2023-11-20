#include "sort.h"

/**
 * cocktail_sort_list - Sorting Aglo
 * @list: to be sorted
*/
void cocktail_sort_list(listint_t **list)
{
	size_t i, n = 0;
	int tmp;
	bool repeat = true;
	listint_t *u_head, *u_tail, *forward, *backward;

	if (!list || !*list || !(*list)->next)
		return;

	while ((u_head = u_head->next))
		u_tail = u_head;
	u_head = *list;
	forward = u_head;
	backward = u_tail;
	while (repeat)
	{
		repeat = false;
		while (forward && forward->next)
		{
			if (forward > forward->next)
		}
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				repeat = true;
				print_array(array, size);
			}
		}
		n--;
	}
}
