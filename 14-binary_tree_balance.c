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
