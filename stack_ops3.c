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

/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)top->n);
}

/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;


	while (current)
	{
		if (current->n < 1 || current->n > 127)
			break;

		printf("%c", (char)current->n);
		current = current->next;
	}

	printf("\n");
	(void)line_number;
}

/**
 * rotl - rotates the stack to the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	 stack_t *new_top, *current;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	new_top = (*stack)->next;
	current = new_top;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	(*stack)->next = NULL;
	new_top->prev = NULL;

	*stack = new_top;
	(void)line_number;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top, *current;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	new_top = current;

	while (current->next != NULL)
	{
		new_top = current;
		current = current->next;
	}

	new_top->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;

	(void)line_number;
}
