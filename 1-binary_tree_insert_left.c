#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: The newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *__new_node;

    /* Check if the parent node is valid */
if (!parent)
return (NULL);

    /* Allocate memory for the new node */
__new_node = malloc(sizeof(binary_tree_t));

    /* Check if memory allocation was successful */
if (!__new_node)
return (NULL);

    /* Initialize the new node with the provided values */
__new_node->n = value;
__new_node->parent = parent;
__new_node->left = NULL;
__new_node->right = NULL;

    /* Connect the new node to the left child of the parent */
if (parent->left != NULL)
{
__new_node->left = parent->left;
parent->left->parent = __new_node;
}
parent->left = __new_node;

    /* Return the newly created node */
return (__new_node);
}
