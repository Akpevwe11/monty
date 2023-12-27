#include "monty.h"

void process_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
