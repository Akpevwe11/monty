#include "monty.h"

/**
 * stack_add - adds the top two elements of the stack
 * @stack: stack
 * @line_num: line number
 *
 * Return: void
 */
void stack_add(stack_t **stack, unsigned int line_num)
{
	stack_t *current_node = *stack;
	char *result_string;
	int prev__is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_global();
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (current_node->next->next)
	{
		current_node = current_node->next;
	}

	result_string = int_to_string(current_node->n + current_node->next->n);

	stack_pop(stack, line_num);
	stack_pop(stack, line_num);

	s.number = result_string;

	prev__is_stack = s.is_stack;
	s.is_stack = 1;

	stack_push(stack, line_num);

	s.is_stack = prev__is_stack;

	free(result_string);
}

/**
 * stack_nop - does nothing to the stack
 * @stack: stack
 * @line_num: line number
 *
 * Return: void
 */
void stack_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;


}


/**
 * stack_enqueue - adds an element to the queue
 * @queue: a pointer to the queue
 * @element: the element to add to the queue
 *
 * Return: void
 */

void stack_enqueue(stack_t **queue, int element)
{
	stack_t *new_elemnt, *current_front = *queue;

	new_element = malloc(sizeof(stack_t));

	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	new_element->n = element;
	new_element->prev = NULL;
	new_element->next = current_front;
	if (*queue)
		current_front->prev = new_element;
	*queue = new_element;
}

