#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define  _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int _atoi(char *format, int k, int l);
int checkpush(char *s1, int k, int *start, int *end, int *line_n);
int checkcmd(char *s1, char *s2, int j);
int checkline(char *s, stack_t **head, int *line_n);
stack_t *push(stack_t **head, const int n);
size_t pall(const stack_t *h);
int pop(stack_t **head);
size_t pint(const stack_t *h);
size_t swap(const stack_t *h);
size_t add(const stack_t *h);
#endif /* MONTY_H */
