/**
 * num_checker - checks if an array of chars is a number
 * @line_num: line number
 *
 * Return: void
 */

void num_checker(unsigned int line_num)
{
	int curr_idx = 0;

	if (s.number[curr_idx] == '-' || s.number[curr_idx] == '+')
		curr_idx++;

	while (s.number[curr_idx])
	{
		if (s.number[curr_idx] < '0' || s.number[curr_idx] > '9')
		{
			free_global();
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}

		curr_idx++;
	}
}

/**
 * free_stack - Frees the stack
 * @stack_head: head of the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack_head)
{
	stack_t *current_node = stack_head, *prev_node;

	while (current_node)
	{
		prev_node = current_node;
		current_node = current_node->next;

		free(prev_node);
	}
}

/**
 * free_global - Frees the global structure
 *
 * Return: void
 */
void free_global(void)
{
	fclose(s.file);
	free(s.buffer);
	free_stack(s.stack);
}
