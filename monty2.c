#include "monty.h"

/**
 * push - prints list element
 *
 * @head: Head of the doubly linked list
 * @n: Element to be added
 *
 * Return: Size of list
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *parse;

	parse = malloc(sizeof(stack_t));
	if (parse == NULL)
		return (NULL);
	if (*head == NULL)
	{
		parse->n = n;
		parse->next = NULL;
		parse->prev = NULL;
		*head = parse;
		return (parse);
	}
	parse->n = n;
	parse->next = *head;
	parse->prev = NULL;
	parse->next->prev = parse;
	*head = parse;
	parse = (*head)->next;
	return (parse);
}

/**
 * pall - prints list element
 *
 * @h: Head of the doubly linked list
 *
 * Return: Size of list
 */
size_t pall(const stack_t *h)
{
	size_t count = 0;
	stack_t *parse;

	if (h == NULL)
		return (0);
	parse = (stack_t *)h;
	while (parse != NULL)
	{
		printf("%d\n", parse->n);
		parse = parse->next;
		count++;
	}
	return (count);
}
/**
 * pint - prints list element
 *
 * @h: Head of the doubly linked list
 *
 * Return: Size of list
 */
size_t pint(const stack_t *h)
{
	if (h != NULL)
		printf("%d\n", h->n);
	else
		printf("L<line_number>: can't pint, stack empty");
	printf("\n");
	return (1);
}
/**
 * pop - deletes list element
 *
 * @head: Head of the doubly linked list
 *
 * Return: 1 if success
 */
int pop(stack_t **head)
{
	stack_t *parse;
	unsigned int i = 0, index = 0;

	if (*head == NULL)
	{
		printf("L<line_number>: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	parse = *head;
	while (parse != NULL)
	{
		if (i == index)
		{
			if (index != 0)
			{
				parse->prev->next = parse->next;
				if (parse->next != NULL)
					parse->next->prev = parse->prev;
			}
			else
			{
				*head = parse->next;
				if (parse->next != NULL)
					parse->next->prev = NULL;
			}
			free(parse);
			return (1);
		}
		i++;
		parse = parse->next;
	}
	return (-1);
}
/**
 * swap - swaps list elements
 *
 * @h: Head of the doubly linked list
 *
 * Return: Size of list
 */
size_t swap(const stack_t *h)
{
	size_t count = 0;
	int swap;

	if (h == NULL || h->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short");
		exit(EXIT_FAILURE);
	}
	else
	{
		swap = h->n;
		((stack_t *)h)->n = h->next->n;
		h->next->n = swap;
	}
	return (count);
}
