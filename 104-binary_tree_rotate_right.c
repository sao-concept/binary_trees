#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *__pivot, *temp_child;

    /* Check if the tree or its left child is NULL*/
if (tree == NULL || tree->left == NULL)
return (NULL);

    /* Set the pivot to be the left child of the input tree*/
__pivot = tree->left;

/* Set the right child of the input tree to be the left child of the pivot*/
temp_child = __pivot->right;
__pivot->right = tree;
tree->left = temp_child;

    /* Update parent pointers */
if (temp_child != NULL)
temp_child->parent = tree;
temp_child = tree->parent;
tree->parent = __pivot;
__pivot->parent = temp_child;

    /* Update the parent's left/right child pointer to the new root (pivot)*/
if (temp_child != NULL)
{
if (temp_child->left == tree)
temp_child->left = __pivot;
else
temp_child->right = __pivot;
}

    /* Return the new root (pivot) after rotation */
return (__pivot);
}
