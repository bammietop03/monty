#include "monty.h"

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
