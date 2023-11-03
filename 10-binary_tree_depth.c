#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates a node depth within a binary tree.
 * @tree: A pointer to the depth meauring node.
 * Return: Function must return 0 if tree is NULL else, return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
