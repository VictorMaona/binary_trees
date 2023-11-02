#include "binary_trees.h"

/**
 * binary_tree_inorder - Applies in-order traversal to a binary tree.
 * @tree: Reference to the tree root node that needs to be climbed.
 * @func: Reference to callable function for every node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
