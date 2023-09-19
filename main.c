#include "monty.h"

int main(int argc, char *argv[])
{
	char opcode[100];
	int value, line_number = 0;
	int fd;
	Stack stack;
	char buffer[100];
	char *token;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack.top = 0;

	while (read(fd, buffer, sizeof(buffer)) > 0)
	{
		token = strtok(buffer, " \t\n");

		while (token != NULL)
		{
			line_number++;

			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n");
				if (token == NULL)
				{
					fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				value = atoi(token);
				push(&stack, value, line_number);
			}
			else if (strcmp(token, "pall") == 0)
			{
				pall(&stack);
			}
			else
			{
				fprintf(stderr, "L%d: Error: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, " \t\n");
		}
	}

	close(fd);
	return 0;
}
