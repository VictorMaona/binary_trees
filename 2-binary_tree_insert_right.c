#include "binary_trees.h"

/**
 * binary_tree_insert_right - In a binary tree, insert a node as
 *                             the right-child of another node.
 * @value: Value to be saved in the newly created node.
 * @parent: Reference to node where right-child should be added.
 *
 * Return: If there is an error or the parent is NULL, NULL.
 *         Otherwise - an identifier for the new node.
 *
 * Description: In the event that a parent already has a right-child
 *              the old right-child is designated as the new node
 *               right-child and the new node replaces the parent.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
