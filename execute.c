#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head of the doubly linked list
 * @counter: line counter
 * @file: pointer to the monty file
 * @content: line content
 * Return: void
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = {
	{"push", push}, {"pall", pall},
	{NULL, NULL}
	};

	unsigned int i = 0;
	char *op_token;

	op_token = strtok(content, " \n\t");

	if (op_token && op_token[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (ops[i].opcode && op_token)
	{
		if (strcmp(op_token, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter);

			return (0);
		}
		i++;
	}

	if (op_token && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_token);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);

		return (1);
	}
}
