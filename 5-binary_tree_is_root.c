#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root.
 * @node: Pointer to the node.
 *
 * Description: This function determines whether a given node is the root of
 * the binary tree. The root is the node with no parent.
 *
 * Return: 1 if the node is the root, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    /* Check if node is NULL */
if (node == NULL)
return (0);

    /* Check if the node has no parent */
if (node->parent == NULL)
return (1);

return (0);
}
