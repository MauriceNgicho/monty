#include "monty.h"

/**
 * nop - Doesn’t do anything.
 * @stack: Double pointer to the stack (unused).
 * @line_number: Line number where the instruction appears (unused).
 *
 * Description: This function literally does nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
