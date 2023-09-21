#include "monty.h"

int mode = 0;

/**
 * isInteger - Checks if argument is an integer
 * @arg: double pointer to head of stack
 *
 * Return: 1 if it's an integer or 0 if not
 */
int isInteger(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		/*Checks for negative number and 0*/
		if (arg[i] == '-' && i == 0)
			continue;
		/* return 1 if it's a digit*/
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	/* 0 if not*/
	return (0);
}

/**
 * stack_mode - Sets the mode to stack (LIFO).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 0;
}

/**
 * queue_mode - Sets the mode to queue (FIFO).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 1;
}

/**
 * push_stack - Pushes a node onto the stack in stack mode (LIFO).
 * @stack: Pointer to the top of the stack.
 * @new_node: Pointer to the new node to push onto the stack.
 */
void push_stack(stack_t **stack, stack_t *new_node)
{
	new_node->next = (*stack) ? *stack : NULL;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * push_queue - Pushes a node onto the queue in queue mode (FIFO).
 * @stack: Pointer to the top of the stack.
 * @new_node: Pointer to the new node to push onto the queue.
 */
void push_queue(stack_t **stack, stack_t *new_node)
{
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		stack_t *last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->next = new_node;
		new_node->prev = last;
		new_node->next = NULL;
	}
}
