/**
 * add_two_elements - Adds the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @line_number: line number in the monty file
 *
 * Return: void
 */

void add_two_elements(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int len = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	result = current->n + current->next->n;
	current->next->n = result;
	*head = current->next;

	free(current);
}
