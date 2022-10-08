#ifndef MONTY_H
#define MONTY_H
/*#define  _GNU_SOURCE*/
#define  _POSIX_C_SOURCE 200809L
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
int checkpush(char *s1, int k, int *start, int *end, unsigned int *line_n);
int checkcmd(char *s1, char *s2, int j, unsigned int line_n);
int checkcomment(char *s);
int checkline(char *s, stack_t **head, unsigned int *line_n);
stack_t *push(stack_t **head, const int n);
void pall(stack_t **h, unsigned int line_n);
void pop(stack_t **head, unsigned int line_n);
void pint(stack_t **h, unsigned int line_n);
void pchar(stack_t **h, unsigned int line_n);
void pstr(stack_t **h, unsigned int line_n);
void swap(stack_t **h, unsigned int line_n);
void add(stack_t **h, unsigned int line_n);
void _sub(stack_t **h, unsigned int line_n);
void _mul(stack_t **h, unsigned int line_n);
void _div(stack_t **h, unsigned int line_n);
void _mod(stack_t **h, unsigned int line_n);
void nop(stack_t **h, unsigned int line_n);
void rotl(stack_t **h, unsigned int line_n);
void rotr(stack_t **h, unsigned int line_n);
void free_stack(stack_t *head);
#endif /* MONTY_H */
