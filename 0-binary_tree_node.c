#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: The newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

  /* Allocate memory for the new node */
binary_tree_t *__new_node = malloc(sizeof(binary_tree_t));

  /* Check if memory allocation was successful */
if (!__new_node)
{
return (NULL);
}

  /* Initialize the new node with the provided values */
__new_node->n = value;
__new_node->parent = parent;
__new_node->left = NULL;
__new_node->right = NULL;

  /* Return the newly created node */
return (__new_node);
}
