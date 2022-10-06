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
	if (*h != NULL)
		printf("%c\n", (*h)->n);
	else
		printf("L%u: can't pint, stack empty", line_n);
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
	if (*h == NULL)
	{
		printf("L%u: can't pint, stack empty", line_n);
		exit(EXIT_FAILURE);
	}
	while (p != NULL)
	{
		if (p->n == 0)
			break;
		printf("%c", p->n);
		p = p->next;
	}
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
		printf("L%u: can't pint, stack empty", line_n);
		exit(EXIT_FAILURE);
	}
	tmp = (*h)->n;
	while (p2->next != NULL)
	{
		l++;
		p1 = p2;
		p2 = p2->next;
		p1->n = tmp;
		tmp = p2->n;
		p2->n = p1->n;
	}
	p2->n = tmp;
	printf("tail:%d\n", l);
}

