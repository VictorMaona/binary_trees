#include "binary_trees.h"

/**
 * binary_tree_is_root - Determines whether node is binary tree root.
 * @node: A reference to the node that needs to be verified.
 *
 * Return: Should the node be a root - 1.
 *         Otherwise is - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
