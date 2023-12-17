#ifndef MONTY_H
#define MONTY_H

#define SIZE 1024

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
 * struct bus_data - container for the program variables
 * @arg: value associated with the structure
 * @file: Pointer to monty file
 * @buf: content of the current line
 * @stack: stack
 * @is_queue: Flag to indicate stack or queue mode
 */
typedef struct bus_data
{
	char *arg;
	FILE *file;
	char *buf;
	stack_t *stack;
	int is_queue;
} bus_data_t;

extern bus_data_t bus;

ssize_t getstdin(char **lineptr, int file);
void stack_push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void add_to_stack(stack_t **head, int n);
void add_two_elements(stack_t **head, unsigned int line_number);
void set_queue_mode(stack_t **head, unsigned int line_number);
void enqueue_node(stack_t **tail, int n);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void nop(stack **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void print_top(stack_t **head, unsigned int line_number);
