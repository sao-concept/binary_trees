#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the parent node of the node to create.
 * @value: Value to put in the new node.
 *
 * Return: The new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *__new_node;

    /* Check if parent is NULL */
if (!parent)
return (NULL);

    /* Allocate memory for the new node */
__new_node = malloc(sizeof(binary_tree_t));
if (!__new_node)
return (NULL);

    /* Initialize new node */
__new_node->n = value;
__new_node->parent = parent;
__new_node->left = NULL;

    /* If parent has a right child, update pointers accordingly */
if (parent->right != NULL)
{
__new_node->right = parent->right;
parent->right->parent = __new_node;
}
else
__new_node->right = NULL;

parent->right = __new_node;

return (__new_node);
}
