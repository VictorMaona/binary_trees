#include "binary_trees.h"

/**
 * binary_tree_delete - Gets rid of a binary tree.
 * @tree: A reference to the tree root node that should be removed.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
