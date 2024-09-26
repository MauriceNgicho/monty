#include "monty.h"

/**
 * pall - prints all the values on the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: current line number in the Monty bytecode file (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* Line number not needed for this function */

	/* Traverse the stack and print each value */
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
