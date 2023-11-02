#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the binary tree leaves.
 * @tree: Pointer to the tree root node where leaves are counted.
 *
 * Return: Number of leaves there are on the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
