#ifndef MONTY_H
#define MONTY_H

#define SIZE 1024
#define DELIMITER "\n\t\r "

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

/**
 * struct global_s - global structure
 * @number: number
 * @file: file
 * @buf: buffer
 * @stack: stack
 */
typedef struct global_s
{
	FILE *file;
	char *buf;
	stack_t *stack;
	int is_stack;
    size_t size;
    char *opcode;
} global_t;

extern global_t s;

extern instruction_t opcodes[];
#endif
