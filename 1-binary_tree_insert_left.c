#include "binary_trees.h"

/**
 * binary_tree_insert_left - adds a node to a binary tree
 *                           as its left-child.
 * @value: Value to be saved in the newly created node.
 * @parent: Pointer to node where left-child should be inserted.
 *
 * Return: If an error occurs if the parent is NULL, NULL.
 *         Otherwise - Pointing at the new node.
 *
 * Description: The new node replaces the old one and
 *              the old left-child becomes the new node
 *              left-child if the parent already has a left-child.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
