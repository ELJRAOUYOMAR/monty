#include "monty.h"
stack_t *stackHead = NULL;

/**
 * main - Entry point
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    open_file(argv[1]);
    free_nodes();
    return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon success, a pointer to the node. Otherwise, NULL.
 */
stack_t *create_node(int data)
{
    stack_t *node;

    node = malloc(sizeof(stack_t));
    if (node == NULL)
    {
        handle_error(4);
    }
    node->next = NULL;
    node->prev = NULL;
    node->n = data; 
    return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
    stack_t *tmp;

    if (stackHead == NULL)
        return;

    while (stackHead != NULL)
    {
        tmp = stackHead;
        stackHead = stackHead->next;
        free(tmp);
    }
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    if (stackHead == NULL)
    {
        stackHead = *new_node;
        return;
    }
    tmp = stackHead;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *new_node;
    (*new_node)->prev = tmp;
}

