#include "binary_trees.h"

/**
 * binary_tree_size - Determines the binary tree size.
 * @tree: Pointer to tree root node used to calculate the size.
 *
 * Return: The tree dimensions.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
