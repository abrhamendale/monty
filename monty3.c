#include "monty.h"

/**
 * add - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void add(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = (*h)->n + (*h)->next->n;
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}
/**
 * ssub - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void ssub(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = (*h)->n - (*h)->next->n;
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}
/**
 * smul - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void smul(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = ((*h)->n) * ((*h)->next->n);
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}
/**
 * sdiv - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void sdiv(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = ((*h)->n) / ((*h)->next->n);
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}
/**
 * smod - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void smod(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = ((*h)->n) % ((*h)->next->n);
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}

