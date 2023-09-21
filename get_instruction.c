#include "monty.h"

/**
 * free_stack - freeallocated memory for the stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

/**
 * match_instruction - Match an instruction and call its
 * corresponding function.
 * @opcode: The opcode to match.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 *
 * Return: 1 if matched and called successfully, 0 if not found.
 */
int match_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar},
		{"pstr", pstr},
<<<<<<< HEAD
		{"stack", stack_mode},
		{"queue", queue_mode},
=======
		{"rotl", rotl},
		{"rotr", rotr},
>>>>>>> 8345f783564c58aea48aa6c415cdf67d3c268626
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (1);
		}
	}

	return (0);
}

/**
 * process_file - Read and process a Monty file.
 * @file_name: The name of the Monty file.
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int process_file(const char *file_name)
{
	stack_t *stack = NULL;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	FILE *file = fopen(file_name, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");

		if (opcode && opcode[0] != '#')
		{
			if (!match_instruction(opcode, &stack, line_number))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
						opcode);
				fclose(file);
				free(line);
				free_stack(&stack);
				return (EXIT_FAILURE);
			}
		}
	}

	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
