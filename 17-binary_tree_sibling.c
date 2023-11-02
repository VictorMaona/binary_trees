#include "binary_trees.h"

/**
 * binary_tree_sibling - Find node sibling in binary tree.
 * @node: pointer to node whose sibling has to be found.
 *
 * Return: If sibling is absent or node is NULL, then NULL.
 *         Otherwise - a pointer to the kin.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
