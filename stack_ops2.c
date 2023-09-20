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

/**
 * sub - Subtracts the top element of the stack from the second top
 * element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next_el, *top = *stack;
	int sub = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_el = (*stack)->next;

	sub = next_el->n - top->n;
	next_el->n = sub;

	*stack = next_el;
	free(top);
}

/**
 * div_opcode - Divides the top element of the stack from the second top
 * element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result, divisor, dividend;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = (*stack)->n;
	dividend = (*stack)->next->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = dividend / divisor;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	(*stack)->n = result;
}

/**
 * mul_opcode - Multiplies the top element of the stack from the second top
 * element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
	int operand1, operand2, result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	operand1 = (*stack)->n;
	operand2 = (*stack)->next->n;

	result = operand1 * operand2;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	(*stack)->n = result;
}
