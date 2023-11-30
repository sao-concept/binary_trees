#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *__pivot, *temp;

    /* Check if the tree or its right child is NULL */
if (tree == NULL || tree->right == NULL)
return (NULL);

    /* Set the pivot to be the right child of the input tree */
__pivot = tree->right;
/* Set the left child of the input tree to be the right child of the pivot */
temp = __pivot->left;
__pivot->left = tree;
tree->right = temp;

    /* Update parent pointers */
if (temp != NULL)
temp->parent = tree;
temp = tree->parent;
tree->parent = __pivot;
__pivot->parent = temp;

    /* Update the parent's left/right child pointer to the new root (pivot) */
if (temp != NULL)
{
if (temp->left == tree)
temp->left = __pivot;
else
temp->right = __pivot;
}

    /* Return the new root (pivot) after rotation */
return (__pivot);
}
