#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next_el, *top = *stack;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	next_el = (*stack)->next;

	sum = top->n + next_el->n;
	next_el->n = sum;

	*stack = next_el;
	free(top);
}

/**
 * nop - Does nothing
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* nop does nothing, so we simply ignore its parameters */
}
