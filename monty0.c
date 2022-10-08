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
		if (format[i] == '-')
			continue;
		if (i == k)
			sum = (int)format[k] - 48;
		else
		{
			sum = sum * 10;
			sum += (int)format[i] - 48;
		}
	}
	if (format[k] == '-')
		sum = -1 * sum;
	return (sum);
}
/**
 * checkcomment - searches for '$' inside a string
 *
 * @s: Input string
 *
 * Return: Exit status
 */
int checkcomment(char *s)
{
	int i;

	for (i = 0 ; s[i] == ' ' ; )
		i++;
	if (s[i] == '#')
		return (1);
	/**
	 *for (i = 0 ; i < (int)strlen(s) ; i++)
	 *{
	 *	if (s[l + i] == '$')
	 *		return (1);
	 *}
	 */
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

int checkpush(char *s1, int k, int *start, int *end, unsigned int *line_n)
{
	unsigned int i = 0, l;

	if (checkcmd(s1, "push", k, *line_n))
	{
		for (l = 0 ; s1[k + 4 + l] == ' ' ;)
			l++;
		if ((int)(k + 4 + l) == (int)strlen(s1) - 1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", *line_n);
			return (0);
		}
		*end = k + 4;
		/*if (s1[k + 4] == ' ')*/
		if ((((int)s1[k + 4 + l] >= 48 && (int)s1[k + 4 + l] <= 57) ||
					s1[k + 4 + l] == '-') && k + 4 + l < strlen(s1))
		{
			for (i = 1 ; s1[k + 4 + i + l] != ' ' && s1[k + 4 + i + l]
					!= '\n' && k + 4 + l + i != strlen(s1) ; i++)
			{
				if ((int)s1[k + 4 + i + l] < 48 || (int)s1[k + 4 + i + l] > 57)
				{
					fprintf(stderr, "L%u: usage: push integer\n", *line_n);
					return (0);
				}
				(*end)++;
			}
			(*end)++;
			*start = l;
			if (i + 4 + l + k == strlen(s1) || s1[k + 4 + i + l] == '\n'
					|| s1[k + 4 + i + l] == ' ')
				return (1);
			fprintf(stderr, "L%u: usage: push integer\n", *line_n);
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
 * @line_n: Line number
 *
 * Return: Exit status
 */

int checkcmd(char *s1, char *s2, int j, unsigned int line_n)
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
	if (s1[j + i] != ' ' && j + i < strlen(s1) - 1)
	{
		fprintf(stderr, "L%u: unknown instruction ", line_n);
		for (i = 0 ; j + i < strlen(s1) && s1[j + i] != ' '
				&& s1[j + i] != '\n'; i++)
			fprintf(stderr, "%c", s1[j + i]);
		fprintf(stderr, "\n");
		exit(EXIT_FAILURE);
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

int checkline(char *s, stack_t **head, unsigned int *line_n)
{
	int start, end;
	unsigned int i, j;
	instruction_t op[] = {{"pall", pall}, {"pint", pint}, {"swap", swap}
		, {"add", add}, {"pop", pop}, {"sub", _sub}, {"div", _div}, {"mul", _mul}
		, {"mod", _mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}
		, {"rotr", rotr}};

	/*printf("----------------Checkline\n");*/
	for (i = 0 ; i < strlen(s) ; i++)
	{
		if (checkcomment(s))
			return (1);
		if (checkpush(s, i, &start, &end, line_n))
		{
			if (s[i + 1] != ' ' && i > strlen(s) - 4)
			{
				printf("L%d: unknown instruction %s\n", *line_n, op[j].opcode);
				exit(EXIT_FAILURE);
			}
			push(head, _atoi(s, start + i + 4, end + start - 1));
			return (1);
		}
		for (j = 0 ; j <= 12 ; j++)
		{
			if (checkcmd(s, op[j].opcode, i, *line_n))
			{
				if (s[i + 4] != ' ' && i > strlen(s) - 4)
				{
					printf("L%d: unknown instruction %s\n", *line_n, op[j].opcode);
					exit(EXIT_FAILURE);
				}
				op[j].f(head, *line_n);
				return (1);
			}
		}
	}
	return (0);
}
