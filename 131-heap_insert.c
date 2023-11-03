
#include "binary_trees.h"

/**
 * heap_insert - Adds a value to the Max Binary Heap.
 * @value: Value to be kept in the newly inserted node.
 * @root: Double pointer to heap root node where value is inserted
 *
 * Return: A pointer to the newly formed node
 *         NULL if unsuccessful
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* remove every node but the lowest level */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * navigate tree to first available space using the binary
	 * Illustration of the quantity of leaves.
	 * In a full tree with 12 nodes, there are 5 leaves on
	 * the tree fourth layer. In binary, 5 is 101. 1 is equivalent to
	 * 0 to the left, right.
	 * 101 == RLR, *root->right->left->right is the first empty node.
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	/* Flip values with parent until parent value is greater than new one. */

	return (new);
}

/**
 * binary_tree_size - quantifies a binary tree's size
 * @tree: tree to gauge its size
 *
 * Return: how big the tree is
 *         If the tree is NULL, 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
