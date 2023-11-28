#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: Pointer to the root of the tree.
 * @func: Pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function.
 *
 * Description: This function traverses a binary tree using post-order traversal,
 * applying a given function to each visited node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /* Check if tree or func is NULL */
if (tree == NULL || func == NULL)
return;

    /* Recursively traverse the left and right subtrees */
binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);

    /* Apply the function to the current node's value */
func(tree->n);
}
