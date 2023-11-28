#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node or the node that
 * shares the same sibling as the parent node.
 * @node: The node to be evaluated.
 *
 * Return: The uncle node or NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    /* Check if the node is NULL or has no parent or grandparent */
if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
return (NULL);

    /* Check if the grandparent has a right child and it is not the parent */
if (node->parent->parent->right != NULL &&
node->parent->parent->right != node->parent)
return (node->parent->parent->right);
    /* Check if the grandparent has a left child and it is not the parent */
else if (node->parent->parent->left != NULL &&
node->parent->parent->left != node->parent)
return (node->parent->parent->left);

return (NULL);
}
