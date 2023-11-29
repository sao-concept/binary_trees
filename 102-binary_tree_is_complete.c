#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Creates a new node for the level order traversal queue.
 * @node: The binary tree node to be contained in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
levelorder_queue_t *__new_node = malloc(sizeof(levelorder_queue_t));
if (__new_node == NULL)
return (NULL);

__new_node->node = node;
__new_node->next = NULL;

return (__new_node);
}

/**
 * free_queue - Frees the memory allocated for a level order traversal queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *current = head, *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}
}

/**
 * push - Adds a binary tree node to the level order traversal queue.
 * @node: The binary tree node to be pushed.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Exits with status code 1 on malloc failure.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail)
{
levelorder_queue_t *new_node = create_node(node);
if (new_node == NULL)
{
free_queue(head);
exit(1);
}

(*tail)->next = new_node;
*tail = new_node;
}

/**
 * pop - Removes the head of the level order traversal queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
levelorder_queue_t *tmp = (*head)->next;
free(*head);
*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 *
 * Description: Exits with status code 1 on malloc failure.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
levelorder_queue_t *head, *tail;
unsigned char flag = 0;

if (tree == NULL)
return (0);

head = tail = create_node((binary_tree_t *)tree);
if (head == NULL)
exit(1);

while (head != NULL)
{
if (head->node->left != NULL)
{
if (flag == 1)
{
free_queue(head);
return (0);
}
push(head->node->left, head, &tail);
}
else
flag = 1;

if (head->node->right != NULL)
{
if (flag == 1)
{
free_queue(head);
return (0);
}
push(head->node->right, head, &tail);
}
else
flag = 1;

pop(&head);
}

return (1);
}
