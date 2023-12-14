#include "monty.h"

global_t s;

/**
 * get_stack_func - gets the function associated to an opcode
 * @opcode: the opcode
 * @line: line number
 *
 * Return: function of opcode
*/

void (*get_stack_func(char *opcode, unsigned int line))(stack_t**, unsigned int)
{

}

/**
 * set_global - sets the global structure
 * @filename: file 
 * @st: stack
 * @num: number 
 * @buff: buffer 
 * @stk: stack or queue 
 * 
 * Return: void
*/

void set_global(FILE *filename, stack_t *st, char *num, char *buff, int stk)
{
    s.file = filename; 
    s.stack = st; 
    s.is_stack = stk; 
    s.number = num;
    s.buf = buff;
}

/**
 * main - monty intepreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1]);

	return (0);
}
