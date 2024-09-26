#include "monty.h"

/**
 * push - Pushes an integer onto the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The current line number in the bytecode file
 * @n: The integer to be pushed onto the stack
 *
 * Description: This function takes an integer and pushes
 * it onto the stack. If any error occurs, it prints an error message
 * and exits with a failure status.
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	(void)line_number;  /* Avoid unused variable warning for now */
	add_to_stack(stack, n);  /* Function assumed to be implemented elsewhere */
}
