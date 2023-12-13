#include "monty.h"
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

