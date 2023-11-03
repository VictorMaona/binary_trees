#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Determines if node is leaf in a binary tree.
 * @node: A reference to node that needs to be verified.
 *
 * Return: If a leaf is the node, then 1.
 *         Otherwise give - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
