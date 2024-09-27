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
	char buffer[BUFFER_SIZE];
	char *opcode, *arg;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		line_number++;
		opcode = strtok(buffer, " \n");

		if (opcode == NULL || opcode[0] == '#')
			continue; /* Skip comments or empty lines */

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			push(&stack, line_number, arg); /* Call the push function */
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number); /* Call the pall function */
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number); /* Call the pint function */
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number); /* Call the pop function */
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number); /* Call the swap function */
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number); /* Call the add function */
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number); /* Call the nop function */
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

