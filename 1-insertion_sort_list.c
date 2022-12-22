#include "sort.h"

/**
 * insertion_sort_list - sort for list
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
	int flag = 0;
	listint_t *tmp = NULL, *aux = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev;
			if (tmp->next->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;

			tmp->prev = tmp->next;
			tmp->next = tmp->next->next;
			tmp->prev->next = tmp;
			if (tmp->next)
				tmp->next->prev = tmp;

			tmp = tmp->prev;
			print_list(*list);

			if (tmp->prev && tmp->prev->n > tmp->n)
			{
				if (flag == 0)
					aux = tmp->next;
				flag = 1;
				tmp = tmp->prev;
				continue;
			}
		}
		if (flag == 0)
			tmp = tmp->next;
		else
			tmp = aux, flag = 0;
	}
}
