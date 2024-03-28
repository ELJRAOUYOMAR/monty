#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void elj_open_file(char *elj_file_name);
int elj_parse_line(char *elj_buffer, int elj_line_number, int elj_format);
void elj_read_file(FILE *);
int elj_len_chars(FILE *);
void elj_find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *elj_create_node(int elj_n);
void elj_free_nodes(void);
void elj_print_stack(stack_t **, unsigned int);
void elj_add_to_stack(stack_t **, unsigned int);
void elj_add_to_queue(stack_t **, unsigned int);

void elj_call_fun(op_func elj_func, char *elj_op, char *elj_val, int elj_ln, int elj_format);

void elj_print_top(stack_t **, unsigned int);
void elj_pop_top(stack_t **, unsigned int);
void elj_nop(stack_t **, unsigned int);
void elj_swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void elj_add_nodes(stack_t **, unsigned int);
void elj_sub_nodes(stack_t **, unsigned int);
void elj_div_nodes(stack_t **, unsigned int);
void elj_mul_nodes(stack_t **, unsigned int);
void elj_mod_nodes(stack_t **, unsigned int);

/*String operations*/
void elj_print_char(stack_t **, unsigned int);
void elj_print_str(stack_t **, unsigned int);
void elj_rotl(stack_t **, unsigned int);

/*Error hanlding*/
void elj_err(int elj_error_code, ...);
void elj_more_err(int elj_error_code, ...);
void elj_string_err(int elj_error_code, ...);
void elj_rotr(stack_t **, unsigned int);

#endif

