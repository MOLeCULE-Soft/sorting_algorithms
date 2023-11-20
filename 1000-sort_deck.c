#include "deck.h"

void sort_deck(deck_node_t **list);
void sort_deck1(deck_node_t **list);
int get_card_value(const char *);
int get_surrogate_node_value(deck_node_t *);

/**
 * sort_deck - Sorting algo for deck of cards
 * @list: to be sorted
*/
void sort_deck(deck_node_t **list)
{
	deck_node_t *node, *prev, *next, *tmp;

	if (!list || !*list || !(*list)->next)
		return;
	next = (*list)->next;
	while (next)
	{
		node = next;
		prev = next->prev;
		while (prev)
		{
			if (get_surrogate_node_value(node) >= get_surrogate_node_value(prev))
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
			}
		}
	}
}

/**
 * get_card_value - numeric value of kind
 * @kind: of card
 *
 * Return: value of @kind
*/
int get_card_value(const char *kind)
{
	if (kind)
	{
		if (strlen(kind) == 1 && isdigit(*kind))
			return (atoi(kind));
		else if (strcmp(kind, "Ace") == 0)
			return (1);
		else if (strcmp(kind, "10") == 0)
			return (10);
		else if (strcmp(kind, "Jack") == 0)
			return (11);
		else if (strcmp(kind, "Queen") == 0)
			return (12);
		else if (strcmp(kind, "King") == 0)
			return (13);
	}
	return (0);
}

/**
 * get_surrogate_node_value - numeric surrogate value of node
 * @node: in linked list
 *
 * Return: surrogate value of @node
*/
int get_surrogate_node_value(deck_node_t *node)
{
	if (node)
		return (node->card->kind * 13 + get_card_value(node->card->value));
	return (0);
}
