#include "monty.h"

void open_file(char *file_name)
{
	FILE *file_ptr = fopen(file_name, "r");

	if (file_name == NULL || file_ptr == NULL)
		handle_error(2, file_name);

	read_file(file_ptr);
	fclose(file_ptr);
}

void read_file(FILE *file_ptr)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, file_ptr) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		handle_error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_handler(opcode, value, line_number, format);
	return (format);
}

void find_handler(char *opcode, char *value, int line_num, int format)
{
	int i;
	int flag;

	instruction_t handler_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_data},
		{"sub", sub_data},
		{"div", div_data},
		{"mul", mul_data},
		{"mod", mod_data},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; handler_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, handler_list[i].opcode) == 0)
		{
			call_handler(handler_list[i].f, opcode, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_error(3, line_num, opcode);
}

void call_handler(op_func handler, char *op, char *val, int line_num, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			handle_error(5, line_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handle_error(5, line_num);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			handler(&node, line_num);
		if (format == 1)
			add_to_queue(&node, line_num);
	}
	else
		handler(&head, line_num);
}

