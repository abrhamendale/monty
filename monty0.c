#include "monty.h"

int _atoi(char *format, int k, int l)
{
	int i = 0;
	int sum = 0;

	printf("---------------_atoi\n");
	printf("format:%d k:%d l:%d\n", (int)format[k], k, l);
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
	printf("%d\n", sum);
	printf("end---------------_atoi\n");
	return (sum);
}
int checkcmdend(char *s, int l)
{
	int i;

	for (i = 0 ; i < (int)strlen(s) ; i++)
	{printf("$:%c\n", s[l + i]);
		if (s[l + i] == '$')
			return (1);
	}
	return (0);
}
int checkpush(char *s1, int k, int *start, int *end)
{
	unsigned int i, l;

	printf("---------------checkpush\n");
	if(checkcmd(s1, "push", k))
	{printf("11111\n");
		if ((k + 4) == (int)strlen(s1))
		{
			printf("L<line_number>: unknown instruction <opcode>/n");
			return (0);
		}printf("11111\n");
		printf("%c\n", s1[k + 1]);
		if (!checkcmdend(s1, k + 4))
			return (0);
		*end = k + 4;
		printf("11111\n");
		for (l = 0 ; s1[k + 4 + l] == ' ' ;)
			l++;
			/*printf("%c\n", s1[k + 4 + l]);*/
		if ((int)s1[k + 4 + l] > 48 || (int)s1[k + 4 + l] < 57)
		/*if (s1[k + 4] == ' ')*/
		{printf("11111\n");
			for (i = 0 ; s1[k + 4 + i + l] != ' ' && s1[k + 4 + i + l] != '$' ; i++)
			{
				if ((int)s1[k + 4 + i + l] < 48 || (int)s1[k + 4 + i + l] > 57)
				{
					printf("L<line_number>: unknown instruction <opcode>/n");
					return (0);
				}
				printf("s1[%d + 4 + %u + %u]:%c\n", k, i, l, s1[k + 4 + i + l]);
				(*end)++;
			}
			printf("%d\n", *end);
			/*
			if (s1[k + 4 + i] == ' ')

			else if (s1[k + 4 + i] == '$')
			*/
			*start = l;
			printf("%lu %d\n", strlen(s1), 4 + i + l);
			if (i + 4 + l + k == strlen(s1) || s1[k + 4 + i + l] == '$' || s1[k + 4 + i + l] == ' ')
				return(1);
		}
	}
	printf("end---------------checkpush\n");
	return (0);
}
int checkcmd(char *s1, char *s2, int j)
{
	unsigned int i;

	printf("---------------checkcmd\n");
	printf("%c\n", s1[j]);
	for (i = 0 ; i < strlen(s2) ; i++)
	{
		if ((unsigned int)j + i == strlen(s1))
			return (0);
		if (s1[j + i] != s2[i])
			return (0);
		else
			continue;
	}
	printf("end---------------checkcmd\n");
	return (1);
}
int checkline(char *s, stack_t **head)
{
	int start, end;
	unsigned int i;
	/*
	instruction_t m[] = {{push, }, {pall, }, {pint, }, {pop, }, {swap, }, {add, }, {nop, }, {sub, }, {div, }, {mul, }, {mod, }, {pchar, }, {pstr, }, {rotl, }, {rotr, }, {stack, }, {queue, }};
	*/

	printf("---------------checkline\n");
	for (i = 0 ; i < strlen(s) ; i++)
	{
		printf("size of line:%lu\n",strlen(s) - 1);
		if (s[i] == '$')
			return (0);
		if (checkpush(s, i, &start, &end))
		{
			push(head, _atoi(s, start + i + 4, end + start - 1));
			return (1);
		}
		else if (checkcmd(s, "pall", i) && checkcmdend(s, i + 4))
		{
			printf("Print Head:%d\n", (*head)->n);
			pall(*head);
			break;
		}
	}
	printf("end---------------checkline\n");
	return (0);
}
