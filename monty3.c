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
		fprintf(stderr, "L%u: can't add, stack too short", line_n);
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
 * _sub - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void _sub(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = (*h)->next->n - (*h)->n;
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}
/**
 * _mul - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void _mul(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short", line_n);
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
 * _div - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void _div(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by 0", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = ((*h)->next->n) / ((*h)->n);
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}
/**
 * _mod - swaps list elements
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void _mod(stack_t **h, unsigned int line_n)
{
	int sum;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by 0", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*head = (stack_t *)h;*/
		sum = ((*h)->next->n) % ((*h)->n);
		pop(h, line_n);
		pop(h, line_n);
		push(h, sum);
	}
}

