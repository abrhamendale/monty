#include "monty.h"

/**
 * push - prints list element
 *
 * @head: Head of the doubly linked list
 * @n: element to be added
 *
 * Return: Size of list
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *parse;

	/*printf("---------------PUSH\n");*/
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
 * @line_n: Line number
 *
 * Return: Size of list
 */
void pall(stack_t **h, unsigned int line_n)
{
	stack_t *parse;

	parse = *h;
	if (*h == NULL && line_n)
	{
	/*
	 *	 fprintf(stderr, "L%u Stack empty\n", line_n);
	 *	 exit(EXIT_FAILURE);
	 */
	}
	while (parse != NULL)
	{
		printf("%d\n", parse->n);
		parse = parse->next;
	}
}
/**
 * pint - prints list element
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void pint(stack_t **h, unsigned int line_n)
{
	if (*h != NULL)
		printf("%d", (*h)->n);
	else
		fprintf(stderr, "L%d: can't pint, stack empty", line_n);
	printf("\n");
}
/**
 * pop - deletes list element
 *
 * @head: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: 1 if success
 */
void pop(stack_t **head, unsigned int line_n)
{
	stack_t *parse;
	unsigned int i = 0, index = 0;

	parse = *head;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
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
			break;/*exit(EXIT_SUCCESS);*/
		}
		i++;
		parse = parse->next;
	}
}
/**
 * swap - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void swap(stack_t **h, unsigned int line_n)
{
	int swap;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		swap = (*h)->n;
		(*h)->n = (*h)->next->n;
		(*h)->next->n = swap;
	}
}
