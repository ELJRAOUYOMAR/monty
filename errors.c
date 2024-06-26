#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void elj_err(int elj_error_code, ...)
{
	va_list elj_ag;
	char *elj_op;
	int elj_l_num;

	va_start(elj_ag, elj_error_code);
	switch (elj_error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(elj_ag, char *));
			break;
		case 3:
			elj_l_num = va_arg(elj_ag, int);
			elj_op = va_arg(elj_ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", elj_l_num, elj_op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(elj_ag, int));
			break;
		default:
			break;
	}
	elj_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void elj_more_err(int elj_error_code, ...)
{
	va_list elj_ag;
	char *elj_op;
	int elj_l_num;

	va_start(elj_ag, elj_error_code);
	switch (elj_error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(elj_ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(elj_ag, int));
			break;
		case 8:
			elj_l_num = va_arg(elj_ag, unsigned int);
			elj_op = va_arg(elj_ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", elj_l_num, elj_op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(elj_ag, unsigned int));
			break;
		default:
			break;
	}
	elj_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void elj_string_err(int elj_error_code, ...)
{
	va_list elj_ag;
	int elj_l_num;

	va_start(elj_ag, elj_error_code);
	elj_l_num = va_arg(elj_ag, int);
	switch (elj_error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", elj_l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", elj_l_num);
			break;
		default:
			break;
	}
	elj_free_nodes();
	exit(EXIT_FAILURE);
}

