#include "monty.h"

/**
 * open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void elj_open_file(char *elj_file_name)
{
	FILE *elj_fd = fopen(elj_file_name, "r");

	if (elj_file_name == NULL || elj_fd == NULL)
		elj_err(2, elj_file_name);

	elj_read_file(elj_fd);
	fclose(elj_fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void elj_read_file(FILE *elj_fd)
{
	int elj_line_number, elj_format = 0;
	char *elj_buffer = NULL;
	size_t elj_len = 0;

	for (elj_line_number = 1; getline(&elj_buffer, &elj_len, elj_fd) != -1; elj_line_number++)
	{
		elj_format = elj_parse_line(elj_buffer, elj_line_number, elj_format);
	}
	free(elj_buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int elj_parse_line(char *elj_buffer, int elj_line_number, int elj_format)
{
	char *elj_opcode, *elj_value;
	const char *elj_delim = "\n ";

	if (elj_buffer == NULL)
		elj_err(4);

	elj_opcode = strtok(elj_buffer, elj_delim);
	if (elj_opcode == NULL)
		return (elj_format);
	elj_value = strtok(NULL, elj_delim);

	if (strcmp(elj_opcode, "stack") == 0)
		return (0);
	if (strcmp(elj_opcode, "queue") == 0)
		return (1);

	elj_find_func(elj_opcode, elj_value, elj_line_number, elj_format);
	return (elj_format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void elj_find_func(char *elj_opcode, char *elj_value, int elj_ln, int elj_format)
{
	int i;
	int elj_flag;

	instruction_t func_list[] = {
		{"push", elj_add_to_stack},
		{"pall", elj_print_stack},
		{"pint", elj_print_top},
		{"pop", elj_pop_top},
		{"nop", elj_nop},
		{"swap", elj_swap_nodes},
		{"add", elj_add_nodes},
		{"sub", elj_sub_nodes},
		{"div", elj_div_nodes},
		{"mul", elj_mul_nodes},
		{"mod", elj_mod_nodes},
		{"pchar", elj_print_char},
		{"pstr", elj_print_str},
		{"rotl", elj_rotl},
		{"rotr", elj_rotr},
		{NULL, NULL}
	};

	if (elj_opcode[0] == '#')
		return;

	for (elj_flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(elj_opcode, func_list[i].opcode) == 0)
		{
			elj_call_fun(func_list[i].f, elj_opcode, elj_value, elj_ln, elj_format);
			elj_flag = 0;
		}
	}
	if (elj_flag == 1)
		elj_err(3, elj_ln, elj_opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void elj_call_fun(op_func elj_func, char *elj_op, char *elj_val, int elj_ln, int elj_format)
{
	stack_t *elj_node;
	int elj_flag;
	int i;

	elj_flag = 1;
	if (strcmp(elj_op, "push") == 0)
	{
		if (elj_val != NULL && elj_val[0] == '-')
		{
			elj_val = elj_val + 1;
			elj_flag = -1;
		}
		if (elj_val == NULL)
			elj_err(5, elj_ln);
		for (i = 0; elj_val[i] != '\0'; i++)
		{
			if (isdigit(elj_val[i]) == 0)
				elj_err(5, elj_ln);
		}
		elj_node = elj_create_node(atoi(elj_val) * elj_flag);
		if (elj_format == 0)
			elj_func(&elj_node, elj_ln);
		if (elj_format == 1)
			elj_add_to_queue(&elj_node, elj_ln);
	}
	else
		elj_func(&head, elj_ln);
}

