#include "monty.h"

/**
 * free_stack - Frees the stack
 * @stack: head of the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack, *prev_node;

	while (current_node != NULL)
	{
		prev_node = current;
		current = current->next;

		free(prev_node);
	}
}


/**
* len - length of stack
*
* @stack: pointer that point to stack
*
* Return: unsigned int
**/
unsigned int len(stack_t **stack)
{
	stack_t *current;
	unsigned int len = 0;

	current = *stack;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (l);
}
