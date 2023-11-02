#include "binary_trees.h"

/**
 * tree_size - Calculates the binary tree height as a whole.
 * @tree: pointer to the trees root node such that the height
 *
 * Return: 0 if the tree is NULL, or height
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - Sort array heap binary max heap.
 *
 * @heap: Pointer to the heap root node for conversion
 * @size: Location where the array size is stored
 *
 * Return: Pointer to a descendingly ordered array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
