#include "monty.h"
#include <ctype.h>

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The line number where the instruction appears.
 * @arg: The argument to push onto the stack.
 *
 * Description: If the argument is not a valid integer, print an error
 * and exit with the status EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int n;

    if (!is_number(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    add_to_stack(stack, n);
}
