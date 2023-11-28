#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree from a given node.
 * Size is the total number of nodes in the tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Size of the tree from the given node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* Check if the node is NULL */
if (tree == NULL)
return (0);

    /* Recursively calculate the size of the left and right subtrees */
size_t size = binary_tree_size(tree->left) + 1;
size += binary_tree_size(tree->right);

return (size);
}
