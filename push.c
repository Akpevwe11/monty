#include "monty.h"

/**
 * stack_push - add node to the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: void
*/
void stack_push(stack_t **head, unsigned int line_number)
{
	int value, index = 0, non_digit = 0;

	if (bus.arg)
	{

		if (bus.arg[0] == '-')
			index++;

		while (bus.arg[index] != '\0')
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				non_digit = 1;
			index++;
		}

		if (non_digit == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.buff);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.buff);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.is_stack == 0)
		add_to_stack(head, value);
	else
		add_to_queue(head, value);

}
