#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * A full binary tree is a tree in which each node has
 * either zero or two children.
 * @tree: Pointer to the root of the tree to be evaluated.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
int is_full_left, is_full_right;

    /* Check if the tree is NULL or has only one child */
if (tree == NULL ||
(tree->left == NULL && tree->right != NULL) ||
(tree->left != NULL && tree->right == NULL))
return (0);

    /* Check if the node is a leaf (no left or right child) */
if (tree->left == NULL && tree->right == NULL)
return (1);

    /* Recursively check if both the left and right subtrees are full */
is_full_left = binary_tree_is_full(tree->left);
is_full_right = binary_tree_is_full(tree->right);

    /* Return 1 if both subtrees are full, otherwise return 0 */
return (is_full_right && is_full_left);
}
