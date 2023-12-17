#include "monty.h"
/**
 * pall - Prints the elements of the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line numbr in the monty file
 *
 * Return: Void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *head;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
