#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node.
 *
 * Description: This function determines whether a given node is a leaf in a
 * binary tree. A leaf node is a node with no children.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    /* Check if node is NULL */
if (node == NULL)
return (0);

    /* Check if the node has no left or right child */
if (node->left == NULL && node->right == NULL)
return (1);

return (0);
}
