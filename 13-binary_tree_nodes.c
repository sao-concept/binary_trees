#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree
 * that have at least one child.
 * @tree: Pointer to the root of the tree to be evaluated.
 *
 * Return: The number of nodes with at least one child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    /* Check if the node is NULL or has no children */
if (tree == NULL || (tree->left == NULL && tree->right == NULL))
return (0);

/*
 * Return 1 plus the sum of nodes with at least one child in
 * the left and right subtrees
 */
return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
