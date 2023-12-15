#include "monty.h"

/**
* find_opcode - find operation code
*
* @stack: stack pointer
* @opcode: user input opcode
* @lnum: line number
*
* Return: Always 1 (Success) or stderr
**/
int find_opcode(stack_t **stack, char *opcode, int lnum)
{
	instruction_t opcodes[] = {
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pint", op_pint},
		{NULL, NULL}
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
