#include "sort.h"

/**
 * insertion_sort_list - Sorts a DLL wit a Insertion Sort implementation
 *
 * @list: The DLL to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *tmp_back = NULL;

	if (list)
		while (tmp->next)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_forward(list, tmp);
				print_list(*list);
				tmp_back = tmp->prev;
				while (tmp_back->prev && (tmp_back->prev->n > tmp_back->n))
				{
					swap_back(list, tmp_back);
					print_list(*list);
				}
			}
			else
				tmp = tmp->next;
		}
}

/**
 * swap_forward - Swaps two nodes forward
 *
 * @head: The address of the Head of DLL
 * @to_swap: The node to be swapped
 */

void swap_forward(listint_t **head, listint_t *to_swap)
{
	if (to_swap->prev == NULL)
		*head = to_swap->next;
	else
		to_swap->prev->next = to_swap->next;

	to_swap->next->prev = to_swap->prev;

	if (to_swap->next->next)
		to_swap->next->next->prev = to_swap;

	to_swap->prev = to_swap->next;

	to_swap->next = to_swap->next->next;

	to_swap->prev->next = to_swap;
}

/**
 * swap_back - Swaps two nodes back
 *
 * @head: The address of the Head of DLL
 * @to_swap: The node to be swapped
 */

void swap_back(listint_t **head, listint_t *to_swap)
{
	if (to_swap->next)
		to_swap->next->prev = to_swap->prev;

	to_swap->prev->next = to_swap->next;

	if (to_swap->prev->prev)
		to_swap->prev->prev->next = to_swap;
	else
		*head = to_swap;

	to_swap->next = to_swap->prev;

	to_swap->prev = to_swap->prev->prev;

	to_swap->next->prev = to_swap;
}
