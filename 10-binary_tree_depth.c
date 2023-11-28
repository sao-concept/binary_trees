#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * Depth is measured from the root parent node going down.
 * @node: Pointer to the node to measure the depth of.
 *
 * Return: Depth of the tree from the given node.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
    /* Check if the node or its parent is NULL */
if (node == NULL || node->parent == NULL)
return (0);

    /* Recursively calculate the depth of the parent node */
return (binary_tree_depth(node->parent) + 1);
}
