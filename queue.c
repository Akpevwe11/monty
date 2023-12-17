#include "monty.h"
/**
 * set_queue_mode - Sets the mode to queue
 * @head: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: No return value
 */

void set_queue_mode(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bus.is_queue = 1;
}

/**
 * enqueue_node - Adds a new node to the tail of the stack
 * @tail: Pointer to the tail of the stack
 * @n: value to be stored in the new node
 *
 * Return: return void
 */
void enqueue_node(stack_t **tail, int n)
{
	stack_t *new_node, *tail;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (tail)
	{
		while (tail->next)
			tail = tail->next;
	}

	if (!tail)
	{
		*tail = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail->next = new_node;
		new_node->prev = tail;
	}
}
