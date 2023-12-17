#include "monty.h"

/**
 * pop - Removes the top element from the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *top;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	top = *head;
	*head = top->next;
	free(top);
}

