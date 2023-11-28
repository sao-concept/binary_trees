#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * A leaf is a node with no children.
 * @tree: Pointer to the root of the tree to be evaluated.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
size_t left_leaves, right_leaves;

/* Initialize variables for the count of leaves in left and right subtrees */
left_leaves = right_leaves = 0;

    /* Check if the node is NULL */
if (tree == NULL)
return (0);

    /* Check if the node is a leaf (no left or right child) */
if (tree->left == NULL && tree->right == NULL)
return (1);

/* Recursively calculate the number of leaves in the left and right subtrees */
left_leaves = binary_tree_leaves(tree->left);
right_leaves = binary_tree_leaves(tree->right);

    /* Return the sum of leaves in the left and right subtrees */
return (left_leaves + right_leaves);
}
