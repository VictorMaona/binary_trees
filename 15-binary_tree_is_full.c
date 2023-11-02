#include "binary_trees.h"

/**
 * is_full_recursive - Recursively determines whether binary tree is full.
 * @tree: Pointer to the tree root node for inspection.
 *
 * Return: 0 if the tree is not filled.
 *         Otherwise 1.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Determines the size of binary tree.
 * @tree: Pointer to the tree root node for verification.
 *
 * Return: If the tree is empty or NULL then 0.
 *         Otherwise is - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
