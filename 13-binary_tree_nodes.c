#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts binary tree nodes that have at least one child.
 * @tree: Pointer to tree root node so that number of nodes can be counted.
 *
 * Return: Function must yield 0 if tree is NULL, otherwise it must node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
