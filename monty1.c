#include "monty.h"

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
	int l = 0;
	stack_t *head;

	head = NULL;
	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL) 
	{
		printf("Error: Can't open file %s", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (nread != -1)
	{
		printf("Line %d\n", l);
		if ((nread = getline(&line, &len, stream)) == -1)
		{	
			printf("End of line %lu:\n", nread);
			break;
		}
		checkline(line, &head);
		l++;
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
