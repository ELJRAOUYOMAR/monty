#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_nop(stack_t **elj_stack, unsigned int elj_line_number)
{
	(void)elj_stack;
	(void)elj_line_number;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_swap_nodes(stack_t **elj_stack, unsigned int elj_line_number)
{
	stack_t *elj_tmp;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)
		elj_more_err(8, elj_line_number, "swap");
	elj_tmp = (*elj_stack)->next;
	(*elj_stack)->next = elj_tmp->next;
	if (elj_tmp->next != NULL)
		elj_tmp->next->prev = *elj_stack;
	elj_tmp->next = *elj_stack;
	(*elj_stack)->prev = elj_tmp;
	elj_tmp->prev = NULL;
	*elj_stack = elj_tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_add_nodes(stack_t **elj_stack, unsigned int elj_line_number)
{
	int elj_sum;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)
		elj_more_err(8, elj_line_number, "add");

	(*elj_stack) = (*elj_stack)->next;
	elj_sum = (*elj_stack)->n + (*elj_stack)->prev->n;
	(*elj_stack)->n = elj_sum;
	free((*elj_stack)->prev);
	(*elj_stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_sub_nodes(stack_t **elj_stack, unsigned int elj_line_number)
{
	int elj_sum;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)

		elj_more_err(8, elj_line_number, "sub");


	(*elj_stack) = (*elj_stack)->next;
	elj_sum = (*elj_stack)->n - (*elj_stack)->prev->n;
	(*elj_stack)->n = elj_sum;
	free((*elj_stack)->prev);
	(*elj_stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_div_nodes(stack_t **elj_stack, unsigned int elj_line_number)
{
	int elj_sum;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)
		elj_more_err(8, elj_line_number, "div");

	if ((*elj_stack)->n == 0)
		elj_more_err(9, elj_line_number);
	(*elj_stack) = (*elj_stack)->next;
	elj_sum = (*elj_stack)->n / (*elj_stack)->prev->n;
	(*elj_stack)->n = elj_sum;
	free((*elj_stack)->prev);
	(*elj_stack)->prev = NULL;
}

