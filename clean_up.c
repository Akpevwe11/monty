#include "monty.h"

/**
 * clean_up - Function that itetrates throughht a stack and free memory
 * @stack: A pointer to the top of the of the stack (linked list)
 *
 * Return: void
 */

void clean_up(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *current = stack;

		stack = stack->next;
		free(current);
	}
}
