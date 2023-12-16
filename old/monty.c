#include "monty.h"

/**
* find_opcode - find operation code
*
* @stack: stack pointer
* @opcode: user input opcode
* @line_number: line number
*
* Return: Always 1 (Success) or stderr
**/
int find_opcode(stack_t **stack, char *opcode, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pop", pop},
		{"swap", swap}
	};
	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, lnum);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opcode);
	exit(EXIT_FAILURE);
}

/**
* process_instruction - process a single instruction
* @stack: stack pointer
* @line: line from the file
* @lnum: line number
*/

void process_instruction(stack_t **stack, char *line, int lnum)
{
	char *opcode, *n;

	opcode = strtok(line, DELIMITER);

	if (opcode == NULL || opcode[0] == '#')
		return;

	if (!strcmp(opcode, "nop"))
		return;
	else if (!strcmp(opcode, "push"))
	{
		n = strtok(NULL, DELIMITER);
		push(stack, n, lnum);
	}
	else
		find_opcode(stack, opcode, lnum);
}

/**
* main - main function
*
* @argc: number of command line arguments
* @argv: list of command line arguments
*
* Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
**/

int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *mf;
	char *buff = NULL;
	size_t lol = 0;
	int line_number = 0;
	stack_t *stack = NULL, *current;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	mf = fopen(argv[1], "r");
	if (mf == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(1);
	}
	while ((getline(&buff, &lol, mf)) != -1)
	{
		line_number++;
		process_instruction(&stack, buff, line_number);
	}
	fclose(mf);
	free(buff);
	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	return (0);

}


