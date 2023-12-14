#include "monty.h"

/**
 * stack_push - Function to handle the push opcode
 * @stack: Double pointer to the top of the stack
 * @line_num: Line number where the opcode appears in the file
 *
 * Return: void
 */

void stack_push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node, *current_node = *stack;
	int num_to_push;

	if (!s.number)
	{
		free_global();
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	num_checker(line_num);
	num_to_push = atoi(s.number);

	if (s.is_stack == 1)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			free_global();
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_node->n = num_to_push;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (!(*stack))
			*stack = new_node;
		else
		{
			while (current_node->next)
			{
				current_node = current_node->next;
			}
			new_node->prev = current_node;
			current_node->next = new_node;
		}
	}
	else
		stack_enqueue(stack, num_to_push);
}
/**
 * stack_pall - Function to handle the pall opcode
 * @stack: Double pointer to the top of the stack
 * @line_num: Line number where the opcode appears in the file
 *
 * Return: void
 */

void stack_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node = *stack;

	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;

		while (current_node)
		{
			printf("%d\n", current_node->n);
			current_node = current_node->prev;
		}
	}

	(void)line_num

}


/**
 * op_pint - prints the value at the top of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void stack_pint(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		free_global();
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next; temp = temp->next)
		;
	printf("%d\n", temp->n);
}

