#include "monty.h"

/**
 * free_stack - prints list element
 *
 * @head: Head of the doubly linked list
 *
 * Return: Size of list
 */
void free_stack(stack_t *head)
{
	stack_t *p1, *p2;

	if (head)
	{
		p1 = p2 = head;
		while (p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		while (p2->prev != NULL)
		{
			free(p1);
			p1 = p2;
			p2 = p2->prev;
		}
		free(p2->next);
		free(p2);
	}
}
/**
 * main - The main function
 *
 * @argc: number of arguments
 * @argv: arguments array
 *
 * Return: Exit status
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	unsigned int l = 1;
	stack_t *head;

	head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		printf("Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (nread != -1)
	{
		nread = getline(&line, &len, stream);
		if (nread == -1)
		{
			/*printf("End of line %lu:\n", nread);*/
			break;
		}
		checkline(line, &head, &l);
		l++;
	}
	free(line);
	fclose(stream);
	free_stack(head);
	exit(EXIT_SUCCESS);
}
