#include "monty.h"
/**
 * add_to_stack - Adds a new node to the stack
 * @stack: Double pointer to the top of the stack
 * @n: Value to be added to the new node
 *
 * Description: Allocates memory for a new node, initializes it with the
 * given value, and adds it to the top of the stack.
 */
void add_to_stack(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
