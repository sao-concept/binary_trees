#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree from a given node.
 * @tree: Pointer to the node of the tree to measure.
 *
 * Return: Height of the tree or 0 if the node is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    /* Check if the node is NULL */
if (tree == NULL)
return (0);

    /* Check if the node is a leaf (no left or right child) */
if (tree->left == NULL && tree->right == NULL)
return (0);

    /* Recursively calculate the height of the left and right subtrees */
size_t left_height = binary_tree_height(tree->left) + 1;
size_t right_height = binary_tree_height(tree->right) + 1;

    /* Return the maximum height between the left and right subtrees */
return (left_height > right_height ? left_height : right_height);
}
