#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * A perfect binary tree is a tree in which all leaf nodes are @ the same level
 * and every non-leaf node has exactly two children.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is perfect, else return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int left_height, right_height, size, pow;

    /* Check if the tree is NULL */
if (tree == NULL)
return (0);

    /* Calculate the height of the left and right subtrees */
left_height = __custom_binary_tree_height(tree->left);
right_height = __custom_binary_tree_height(tree->right);
size = __binary_tree_size(tree);

    /* Check for the case where the tree has only one node */
if (size == 1)
return (1);

/*Check if both subtrees have non-negative heights and are of the same height*/
if (left_height >= 0 && right_height >= 0 && left_height == right_height)
{
/* Calculate the expected size of a perfect binary tree with the same height */
pow = __get_power(left_height + 1);

/* Check if the actual size matches the expected size */
if (pow - 1 == size)
return (1);
}

return (0);
}

/**
 * __get_power - Calculates the power of 2 for a given exponent.
 * @exp: Exponent.
 *
 * Return: Power of 2 for the given exponent.
 */
int __get_power(int exp)
{
int pow, i;

    /* Calculate the power using a loop */
for (i = 0, pow = 1; i <= exp; i++)
pow *= 2;

return (pow);
}

/**
 * __binary_tree_size - Measures the size of a binary tree from a given node.
 * @tree: Pointer to the root node of the tree to measure from.
 *
 * Return: Size of the tree from the given node.
 */
size_t __binary_tree_size(const binary_tree_t *tree)
{
size_t count;

    /* Check if the node is NULL */
if (tree == NULL)
return (0);

    /* Recursively calculate the size of the left and right subtrees */
count = __binary_tree_size(tree->left) + 1;
count += __binary_tree_size(tree->right);

return (count);
}

/**
 * __custom_binary_tree_height - Measures the height of a
 * binary tree from a given node.
 * @tree: Pointer to the node of the tree to measure.
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
