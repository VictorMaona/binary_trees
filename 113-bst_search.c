#include "binary_trees.h"

/**
 * bst_search - Looks through binary search tree for value.
 * @tree: A pointer to BST root node that needs to be searched.
 * @value: The value in the BST to look for.
 * Return: Null if value cannot be located or if the tree is NULL.
 *         Otherwise, a reference to node where the value is located.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
