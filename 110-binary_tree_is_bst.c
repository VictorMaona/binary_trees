#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks binary tree qualifies as binary search tree.
 * @hi: Biggest node value that has been visited thus far.
 * @lo: The value of least-visited node up to this point.
 * @tree: Pointer to the tree root node for verification.
 *
 * Return: 1 if the tree is a legitimate BST; if not, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Determines binary tree qualifies as binary search.
 * @tree: Pointer to tree root node for verification.
 *
 * Return: If tree is legitimate BST, then 1; if not, then 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
