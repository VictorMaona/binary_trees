#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Gives the binary search tree minimal value back.
 * @root: Reference to the BST root node that needs to be searched.
 *
 * Return: The @tree lowest value.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Removes a binary search tree node.
 * @node: A pointer to the BST node that has to be deleted.
 * @root: Reference to the BST root node.
 *
 * Return: Following deletion, pointer to the new root node.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* Only right-child none at all */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* The Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* The two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Recursively eliminates a node from a binary search tree.
 * @root: A pointer to the BST root node, from which a node is to be removed.
 * @node: A pointer to the BST active node.
 * @value: The amount to be taken out of the BST.
 *
 * Return: A pointer to the root node following removal.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Eliminates a binary search tree node.
 * @root: A pointer to the BST root node, from which a node is to be removed.
 * @value: The BST value that should be deleted.
 *
 * Return: Following deletion, pointer to the new root node.
 * Description: The first in-order successor of the node to be
 *              eliminated takes its place if it has two children.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
