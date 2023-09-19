#include "monty.h"

void push(Stack *stack, int value, int line_number)
{
	if (stack->top < STACK_SIZE)
	{
		stack->stack[stack->top++] = value;
	}
	else
	{
		fprintf(stderr, "L%d: Error: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
}

void pall(Stack *stack)
{
	int i;

	for (i = stack->top - 1; i >= 0; i--)
	{
		printf("%d\n", stack->stack[i]);
	}
}
