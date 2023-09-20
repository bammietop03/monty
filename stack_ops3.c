#include "monty.h"

/**
 * mod_opcode - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	int divisor, dividend, result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	dividend = (*stack)->next->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = dividend % divisor;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	(*stack)->n = result;
}
