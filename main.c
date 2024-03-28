#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	elj_open_file(argv[1]);
	elj_free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *elj_create_node(int elj_n)
{
	stack_t *elj_node;

	elj_node = malloc(sizeof(stack_t));
	if (elj_node == NULL)
		elj_err(4);
	elj_node->next = NULL;
	elj_node->prev = NULL;
	elj_node->n = elj_n;
	return (elj_node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void elj_free_nodes(void)
{
	stack_t *elj_tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		elj_tmp = head;
		head = head->next;
		free(elj_tmp);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void elj_add_to_queue(stack_t **elj_new_node, __attribute__((unused))unsigned int ln)
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
	while (elj_tmp->next != NULL)
		elj_tmp = elj_tmp->next;

	elj_tmp->next = *elj_new_node;
	(*elj_new_node)->prev = elj_tmp;

}

