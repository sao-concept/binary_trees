#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *ancestor_first = (binary_tree_t *)first;
binary_tree_t *ancestor_second = (binary_tree_t *)second;

    /* Check if either of the nodes is NULL */
if (!ancestor_first || !ancestor_second)
return (NULL);

    /* Check if both nodes point to the same location in memory */
if (ancestor_first == ancestor_second)
return (ancestor_first);

    /* Move up the tree to find the common ancestor */
while (ancestor_first && ancestor_second)
{
if (ancestor_first == second || !ancestor_first->parent || (!ancestor_first->
parent->parent && second))
return (binary_trees_ancestor(first, ancestor_second->parent));

if (ancestor_second == first || !ancestor_second->parent || (!ancestor_second
->parent->parent && first))
return (binary_trees_ancestor(ancestor_first->parent, second));

ancestor_first = ancestor_first->parent;
ancestor_second = ancestor_second->parent;
}

return (NULL);
}
