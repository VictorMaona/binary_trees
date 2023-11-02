#include "binary_trees.h"

/**
 * binary_tree_postorder - Applies post-order traversal to binary tree.
 * @func: Identifier for a function to be called for every node.
 * @tree: Pointer to the tree root node that needs to be traversed.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
