#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void elj_print_char(stack_t **elj_stack, unsigned int elj_line_number)
{
	int ascii;

	if (elj_stack == NULL || *elj_stack == NULL)
		elj_string_err(11, elj_line_number);

	ascii = (*elj_stack)->n;
	if (ascii < 0 || ascii > 127)
		elj_string_err(10, elj_line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void elj_print_str(stack_t **elj_stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *elj_tmp;

	if (elj_stack == NULL || *elj_stack == NULL)
	{
		printf("\n");
		return;
	}

	elj_tmp = *elj_stack;
	while (elj_tmp != NULL)
	{
		ascii = elj_tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		elj_tmp = elj_tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void elj_rotl(stack_t **elj_stack, __attribute__((unused))unsigned int ln)
{
	stack_t *elj_tmp;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)
		return;

	elj_tmp = *elj_stack;
	while (elj_tmp->next != NULL)
		elj_tmp = elj_tmp->next;

	elj_tmp->next = *elj_stack;
	(*elj_stack)->prev = elj_tmp;
	*elj_stack = (*elj_stack)->next;
	(*elj_stack)->prev->next = NULL;
	(*elj_stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void elj_rotr(stack_t **elj_stack, __attribute__((unused))unsigned int ln)
{
	stack_t *elj_tmp;

	if (elj_stack == NULL || *elj_stack == NULL || (*elj_stack)->next == NULL)
		return;

	elj_tmp = *elj_stack;

	while (elj_tmp->next != NULL)
		elj_tmp = elj_tmp->next;

	elj_tmp->next = *elj_stack;
	elj_tmp->prev->next = NULL;
	elj_tmp->prev = NULL;
	(*elj_stack)->prev = elj_tmp;
	(*elj_stack) = elj_tmp;
}

