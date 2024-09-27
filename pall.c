#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the stack.
 * @line_number: The line number (unused).
 *
 * Description: If the stack is empty, it doesn't print anything.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; /* Suppress unused variable warning */

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
