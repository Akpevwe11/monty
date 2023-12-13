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
