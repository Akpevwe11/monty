#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define UN __attribute__((__unused__))

#define DELIMITER "\n\t\r "
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 **/
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
 * for stack, queues, LIFO, FIFO Holberton project
 **/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t opcodes[];
unsigned int len(stack_t **stack);
void free_stack(stack_t *stack);
void nop(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, char *number_str, unsigned int lnum);
void pall(stack_t **stack, unsigned int lnum);
void pint(stack_t **stack, unsigned int lnum);
int opcode(stack_t **stack, char *opcode, int lnum);
void swap(stack_t **stack, unsigned int lnum);
size_t lol(stack_t *h);
#endif
