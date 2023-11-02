#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Determines whether a node is a binary tree leaf.
 * @node: A pointer for the node that needs to be verified.
 *
 * Return: If the node is leaf like, then 1. Elsewise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - returns the binary tree depth for specific node.
 *
 * @tree: A pointer the node whose depth has to be measured.
 *
 * Return: The node depth.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a binary tree leaf in return.
 * @tree: Pointer to tree root node, where leaf can be located.
 *
 * Return: Pointer to the leaf you encountered first.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Recursively determines if binary tree is perfect.
 * @tree: Pointer to tree root node for inspection.
 * @leaf_depth: Binary tree one leaf depth.
 * @level: The current node level.
 *
 * Return: 1 if the tree is flawless; otherwise, 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Determines the perfectity of a binary tree.
 * @tree: Pointer to the tree root node for inspection.
 *
 * Return: If the tree is not perfect or NULL, 0.
 *         Otherwise is 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
