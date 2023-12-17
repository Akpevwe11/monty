#include "monty.h"
/**
 * print_top - Prints the top element of the stack
 * @head: Pointer to the stack's head
 * @line_number: Line number in the Monty code file
 *
 * Return: void
 */

void print_top(stack_t **head, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
