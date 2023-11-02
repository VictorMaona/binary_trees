#include "binary_trees.h"

/**
 * binary_tree_node - Makes a node in the binary tree.
 * @value: Value must be entered into new node.
 * @parent: A reference to parent node of node to be created.
 *
 * Return: In the event of an error NULL.
 *         Otherwise - the new node pointer.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
