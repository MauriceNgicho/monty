#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * process_file - Processes Monty bytecode file line by line.
 * @file: The Monty bytecode file to process.
 *
 * Description: Reads each line from the file, parses the opcode,
 * and executes the corresponding function.
 */
void process_file(FILE *file)
{
	char buffer[BUFFER_SIZE]; /* Local variable */
	char *opcode, *arg;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		line_number++;
		opcode = strtok(buffer, " \n");

		if (opcode == NULL || opcode[0] == '#')
			continue;  /* Skip comments or empty lines */

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			if (arg == NULL || !is_number(arg))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, line_number, atoi(arg));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * main - Entry point of the Monty bytecode interpreter.
 * @argc: The number of arguments.
 * @argv: An array of arguments (expects Monty bytecode file).
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	process_file(file);
	fclose(file);
	return (EXIT_SUCCESS);
}
