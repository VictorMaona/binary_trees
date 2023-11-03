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
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
