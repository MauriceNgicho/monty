#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the instruction appears.
 *
 * Description: If the stack contains less than two elements,
 * print an error message and exit with status EXIT_FAILURE.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	/* Add the top two elements */
	second->n += first->n;

	/* Remove the top element */
	*stack = second;
	second->prev = NULL;
	free(first);
}
