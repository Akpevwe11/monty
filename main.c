#include "monty.h"

/**
 * find_opcode - find operation code
 * @stack: stack pointer
 * @opcode: user input opcode
 * @line_number: line number
 *
 * Return: Always 1 (success) on stderr
 **/

int find_opcode(stack_t **stack, char *opcode, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", stack_pall},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"pint", stack_pint},
		{NULL, NULL}
	};

	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * main - main function
 * @argc: number of command line arguments
 * @argv: list of command line arguments
 *
 * Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
 **/

int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *file;
	char *buffer = NULL, *opcode, *n;
	size_t size = 0;
	int line_number = 0;
	stack_t *stack = NULL, *current;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = process_file(argv[1]);

	while ((getline(&buffer, &size, file) != -1)
	{
		line_number++;
		opcode = strtok(buffer, DELIMITER);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIMITER);
			stack_push(&stack, n, line_number);
		}
		else
			find_opcode(&stack, opcode, line_number);
	}
	fclose(file);
	free(buffer);
	clean_up(stack);


	return (0);

}
