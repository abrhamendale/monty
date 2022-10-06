#include "monty.h"

/**
 * add - swaps list elements
 *
 * @h: Head of the doubly linked list
 *
 * Return: Size of list
 */
size_t add(const stack_t *h)
{
	size_t count = 0;
	stack_t *head;
	int sum;

	if (h == NULL || h->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short");
		exit(EXIT_FAILURE);
	}
	else
	{
		head = (stack_t *)h;
		sum = head->n + head->next->n;
		pop(&head);
		pop(&head);
		push(&head, sum);
	}
	return (count);
}

