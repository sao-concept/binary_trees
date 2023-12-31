#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * Balance factor is the difference between the left and right subtree heights.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Balance factor(left height minus right height),or 0 otherwise.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left_height, right_height;

    /* Check if the tree is NULL */
if (tree == NULL)
return (0);

    /* Calculate the height of the left and right subtrees */
left_height = __custom_binary_tree_height(tree->left);
right_height = __custom_binary_tree_height(tree->right);

    /* Return the balance factor (left height minus right height) */
return (left_height - right_height);
}

/**
 * __custom_binary_tree_height - Measures the height of a binary tree
 * from a given node.
 * @tree: Pointer to the node of the tree to measure.
 *
 * Description: Edited to work with the balance factor function.
 *
 * Return: Height of the tree or -1 if the node is NULL.
 */
int __custom_binary_tree_height(const binary_tree_t *tree)
{
int left_height, right_height;

    /* Check if the node is NULL */
if (tree == NULL)
return (-1);

    /* Check if the node is a leaf (no left or right child) */
if (tree->left == NULL && tree->right == NULL)
return (0);

    /* Recursively calculate the height of the left and right subtrees */
left_height = __custom_binary_tree_height(tree->left) + 1;
right_height = __custom_binary_tree_height(tree->right) + 1;

    /* Return the maximum height between the left and right subtrees */
return (left_height > right_height ? left_height : right_height);
}
