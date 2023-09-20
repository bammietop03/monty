#include "monty.h"

/**
 * main - Entry point for the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	int result;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	result = process_file(argv[1]);

	return (result);
}
