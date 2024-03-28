#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void elj_add_to_stack(stack_t **elj_new_node, __attribute__((unused))unsigned int elj_ln)
{
	stack_t *elj_tmp;

	if (elj_new_node == NULL || *elj_new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *elj_new_node;
		return;
	}
	elj_tmp = head;
	head = *elj_new_node;
	head->next = elj_tmp;
	elj_tmp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void elj_print_stack(stack_t **elj_stack, unsigned int elj_line_number)
{
	stack_t *elj_tmp;

	(void) elj_line_number;
	if (elj_stack == NULL)
		exit(EXIT_FAILURE);
	elj_tmp = *elj_stack;
	while (elj_tmp != NULL)
	{
		printf("%d\n", elj_tmp->n);
		elj_tmp = elj_tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_pop_top(stack_t **elj_stack, unsigned int line_number)
{
	stack_t *elj_tmp;

	if (elj_stack == NULL || *elj_stack == NULL)
		elj_more_err(7, line_number);

	elj_tmp = *elj_stack;
	*elj_stack = elj_tmp->next;
	if (*elj_stack != NULL)
		(*elj_stack)->prev = NULL;
	free(elj_tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_print_top(stack_t **elj_stack, unsigned int elj_line_number)
{
	if (elj_stack == NULL || *elj_stack == NULL)
		elj_more_err(6, elj_line_number);
	printf("%d\n", (*elj_stack)->n);
}

