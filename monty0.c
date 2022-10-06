#include "monty.h"

/**
 * _atoi - converts a string to number
 *
 * @format: Input string
 * @k: Starting point of the string
 * @l: End point of the string
 *
 * Return: Exit status
 */
int _atoi(char *format, int k, int l)
{
	int i = 0;
	int sum = 0;

	for (i = k ; i <= l ; i++)
	{
		if (i == k)
			sum = (int)format[k] - 48;
		else
		{
			sum = sum * 10;
			sum += (int)format[i] - 48;
		}
	}
	return (sum);
}
/**
 * checkcmdend - searches for '$' inside a string
 *
 * @s: Input string
 * @l: Starting point of the string
 *
 * Return: Exit status
 */
int checkcmdend(char *s, int l)
{
	int i;

	for (i = 0 ; i < (int)strlen(s) ; i++)
	{
		if (s[l + i] == '$')
			return (1);
	}
	return (0);
}
/**
 * checkpush - converts a string to number
 *
 * @s1: Input string
 * @k: Starting point of the string
 * @start: Starting point of the argumet
 * @end: End point of the argument
 * @line_n: The line number
 *
 * Return: Exit status
 */

int checkpush(char *s1, int k, int *start, int *end, int *line_n)
{
	unsigned int i = 0, l;

	if (checkcmd(s1, "push", k))
	{
		if ((k + 4) == (int)strlen(s1))
		{
			printf("L%d: usage:push integer\n", *line_n);
			return (0);
		}
		*end = k + 4;
		for (l = 0 ; s1[k + 4 + l] == ' ' ;)
			l++;
		/*if (s1[k + 4] == ' ')*/
		if ((int)s1[k + 4 + l] > 48 || (int)s1[k + 4 + l] < 57)
		{
			for (i = 0 ; s1[k + 4 + i + l] != ' ' && s1[k + 4 + i + l]
					!= '\n' && k + 4 + l + i != strlen(s1) ; i++)
			{
				if ((int)s1[k + 4 + i + l] < 48 || (int)s1[k + 4 + i + l] > 57)
				{
					printf("L%d: usage:push integer\n", *line_n);
					return (0);
				}
				(*end)++;
			}
			*start = l;
			if (i + 4 + l + k == strlen(s1) || s1[k + 4 + i + l] == '\n'
					|| s1[k + 4 + i + l] == ' ')
				return (1);
			printf("L%d: usage:push integer\n", *line_n);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * checkcmd - Checks for command names inside a string
 *
 * @s1: Input string
 * @s2: Comman name
 * @j: Starting point of the string
 *
 * Return: Exit status
 */

int checkcmd(char *s1, char *s2, int j)
{
	unsigned int i;

	for (i = 0 ; i < strlen(s2) ; i++)
	{
		if ((unsigned int)j + i == strlen(s1))
			return (0);
		if (s1[j + i] != s2[i])
			return (0);
		continue;
	}
	return (1);
}
/**
 * checkline - Searches a line for commands
 *
 * @s: Input string
 * @head: Address of a pointer to the head of the stack
 * @line_n: Line number
 *
 * Return: Exit status
 */

int checkline(char *s, stack_t **head, int *line_n)
{
	int start, end;
	unsigned int i;
	/*
	 * instruction_t m[] = {{push, }, {pall, }, {pint, }, {pop, }
		*, {swap, }, {add, }, {nop, }, {sub, }, {div, }, {mul, }
		*, {mod, }, {pchar, }, {pstr, }, {rotl, }, {rotr, }, {stack, }
		*, {queue, }};
	*/

	for (i = 0 ; i < strlen(s) ; i++)
	{
		if (s[i] == '$')
			return (0);
		if (checkpush(s, i, &start, &end, line_n))
		{
			push(head, _atoi(s, start + i + 4, end + start - 1));
			return (1);
		}
		else if (checkcmd(s, "pall", i))
		{
			pall(*head);
			break;
		}
		else if (checkcmd(s, "pint", i))
		{
			pint(*head);
			break;
		}
		else if (checkcmd(s, "pop", i))
		{
			pop(head);
			break;
		}
		else if (checkcmd(s, "add", i))
		{
			add(*head);
			break;
		}
	}
	return (0);
}
