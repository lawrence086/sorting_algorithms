#include "sort.h"

/**
 * swap - swaps two adjacent nodes in a doubly linked list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 * @list: pointer to the head of the linked list
 * Return: void
 */
void swap(listint_t *node1, listint_t *node2, listint_t **list)
{
	/* Move node2 after node1 */
	node1->next = node2->next;
	if (node1->next != NULL)
		node1->next->prev = node1;

	/* Move node1 before node2 */
	node2->next = node1;
	node2->prev = node1->prev;
	if (node2->prev != NULL)
		node2->prev->next = node2;
	else
		*list = node2;

	node1->prev = node2;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order using
 * the Cocktail shaker sort algorithm
 * @list: pointer to the head of the linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *runner1, *runner2;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	runner1 = (*list);
	runner2 = NULL;

	while (swapped == 1)
	{
		swapped = 0;
		while (runner1->next != NULL && runner1 != runner2)
		{
			if (runner1->n > runner1->next->n)
			{
				swapped = 1;
				swap(runner1, runner1->next, list);
			}
			else
				runner1 = runner1->next;
		}
		runner2 = runner1;
		if (swapped == 0)
			break;

		/* Backward iteration */
		swapped = 0;
		while (runner1->prev != NULL && runner1 != *list)
		{
			if (runner1->n < runner1->prev->n)
			{
				swapped = 1;
				swap(runner1->prev, runner1, list);
			}
			else
				runner1 = runner1->prev;
		}
		*list = runner1;
	}
}
