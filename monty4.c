#include "monty.h"

/**
 * pchar - prints list element
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void pchar(stack_t **h, unsigned int line_n)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((int)(*h)->n > 127 || (int)(*h)->n < 0)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_n);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", (*h)->n);
	}
}
/**
 * nop - prints list element
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void nop(stack_t **h, unsigned int line_n)
{
	if (h || line_n)
		return;
	else
		return;
}
/**
 * pstr - prints list element
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void pstr(stack_t **h, unsigned int line_n)
{
	stack_t *p;

	p = *h;
	if (*h == NULL && line_n)
		printf("\n");
	while (p != NULL)
	{
		if (p->n == 0)
			break;
		if ((int)p->n > 127 || p->n < 0)
			break;
		printf("%c", p->n);
		p = p->next;
	}
	if (*h != NULL)
		printf("\n");
}
/**
 * rotl - prints list element
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void rotl(stack_t **h, unsigned int line_n)
{
	stack_t *p1, *p2;
	int tmp, l = 0;

	p1 = p2 = *h;
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_n);
		exit(EXIT_FAILURE);
	}
	tmp = (*h)->n;
	while (p2->next != NULL)
	{
		l++;
		p1 = p2;
		p2 = p2->next;
		p1->n = p2->n;
	}
	p2->n = tmp;
}
/**
 * rotr - prints list element
 *
 * @h: Head of the doubly linked list
 * @line_n: Line number
 *
 * Return: Size of list
 */
void rotr(stack_t **h, unsigned int line_n)
{
	stack_t *p2;
	int t1, t2, t3;

	p2 = *h;
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_n);
		exit(EXIT_FAILURE);
	}
	while (p2 != NULL)
	{
		t1 = p2->n;
		p2 = p2->next;
	}
	p2 = *h;
	t2 = (*h)->n;
	while (p2->next != NULL)
	{
		t3 = t2;
		p2 = p2->next;
		t2 = p2->n;
		p2->n = t3;
	}
	(*h)->n = t1;
}
