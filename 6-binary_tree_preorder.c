#include "binary_trees.h"

/**
 * binary_tree_preorder - Does a pre-order traversal of a binary tree.
 * @func: Reference to a callable function for every node.
 * @tree: Reference to the tree root node that needs to be climbed.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
