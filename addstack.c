#include "monty.h"
/**
 * add_to_stack - adds a new node to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: new value to be stored in the new node
 *
 * Return: void
 */

void add_to_stack(stack_t **head, int n)
{
	stack_t *new_node, *current;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (current)
		current->prev = new_node;

	new_node->n = n;

	new_node->next = current;

	new_node->prev = NULL;

	*head = new_node;
}
