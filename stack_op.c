#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_mul_nodes(stack_t **elj_stack, unsigned int elj_line_number)
{
	int elj_sum;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)
		elj_more_err(8, elj_line_number, "mul");

	(*elj_stack) = (*elj_stack)->next;
	elj_sum = (*elj_stack)->n * (*elj_stack)->prev->n;
	(*elj_stack)->n = elj_sum;
	free((*elj_stack)->prev);
	(*elj_stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_mod_nodes(stack_t **elj_stack, unsigned int elj_line_number)
{
	int elj_sum;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)

		elj_more_err(8, elj_line_number, "mod");


	if ((*elj_stack)->n == 0)
		elj_more_err(9, elj_line_number);
	(*elj_stack) = (*elj_stack)->next;
	elj_sum = (*elj_stack)->n % (*elj_stack)->prev->n;
	(*elj_stack)->n = elj_sum;
	free((*elj_stack)->prev);
	(*elj_stack)->prev = NULL;
}

