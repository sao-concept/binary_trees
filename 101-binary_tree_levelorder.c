#include "binary_trees.h"
#include <stdlib.h>


/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
levelorder_queue_t *new_node;

    /* Allocate memory for the new node */
new_node = malloc(sizeof(levelorder_queue_t));
if (new_node == NULL)
return (NULL);

/*Initialize the new node with the provided binary tree node and no next node*/
new_node->node = node;
new_node->next = NULL;

return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *tmp;

    /* Iterate through the queue and free each node */
while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t **head,
levelorder_queue_t **tail, void (*func)(int))
{
levelorder_queue_t *new_node;

    /* Call the provided function on the value of the binary tree node */
func(node->n);

/* Push the left child into the queue if it exists */
if (node->left != NULL)
{
new_node = create_node(node->left);
if (new_node == NULL)
{
/* Handle memory allocation failure */
free_queue(*head);
exit(1);
}
(*tail)->next = new_node;
*tail = new_node;
}

/* Push the right child into the queue if it exists */
if (node->right != NULL)
{
new_node = create_node(node->right);
if (new_node == NULL)
{
/* Handle memory allocation failure */
free_queue(*head);
exit(1);
}
(*tail)->next = new_node;
*tail = new_node;
}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
levelorder_queue_t *tmp;

    /* Pop the head of the queue and update the head pointer */
tmp = (*head)->next;
free(*head);
*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
levelorder_queue_t *head, *tail;

    /* Check for NULL tree or NULL function */
if (tree == NULL || func == NULL)
return;

    /* Initialize the queue with the root node */
head = tail = create_node((binary_tree_t *)tree);
if (head == NULL)
return;

    /* Process each node in level-order using the queue */
while (head != NULL)
{
pint_push(head->node, &head, &tail, func);
pop(&head);
}
}
