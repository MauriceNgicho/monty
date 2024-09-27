#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the instruction appears.
 *
 * Description: If the stack contains less than two elements,
 * print an error message and exit with status EXIT_FAILURE.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	/* Swap the values of the top two elements */
	first->prev = second;
	first->next = second->next;

	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;

	*stack = second;
}
