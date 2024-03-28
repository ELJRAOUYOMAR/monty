#include "monty.h"

void print_char(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		handle_more_error(11, line_num);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		handle_string_error(10, line_num);
	printf("%c\n", (*stack)->n);
}

void print_str(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL && temp->n != 0)
	{
		if (temp->n < 0 || temp->n > 127)
			handle_string_error(10, line_num);
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

void rotate_left(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void)line_num;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void rotate_right(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void)line_num;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*stack = temp;
}

