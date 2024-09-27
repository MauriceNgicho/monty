#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty bytecode being executed.
 *
 * Description: If the stack is empty, the function prints an error message
 * and exits with status EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next; /* Move to the next element */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp); /* Free the removed element */
}
