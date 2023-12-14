#include "monty.h"

/**
 * int_to_string - converts an integer to a string
 * @integer: input integer to be converted
 *
 * Return: dynamically allocated string containing the integer as character
*/

char *int_to_string(int integer)
{
	int string_length;
	char *result_string;

	string_length = snprintf(NULL, 0, "%d", integer);
	result_string = malloc(sizeof(char) * (string_length + 1));

	if (result_string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	sprintf(result_string, "%d", integer);

	return result_string;

}




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
