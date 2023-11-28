#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: Pointer to the root of the tree.
 *
 * Description: This function deletes an entire binary tree, including all
 * of its nodes and their data. It uses a recursive approach to delete each
 * node in a post-order traversal.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    /* Check if tree is NULL */
if (tree == NULL)
return;

    /* Recursively delete left and right subtrees */
binary_tree_delete(tree->left);
binary_tree_delete(tree->right);

    /* Free the current node */
free(tree);
}
