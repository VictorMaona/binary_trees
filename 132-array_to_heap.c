#include "binary_trees.h"

/**
 * array_to_heap - Use an array to create Max Binary Heap tree
 * @array: Pointer to array first member that has to be transformed
 * @size: The quantity of elements within the array.
 *
 * Return: a pointer to Binary Heap root node after it was formed
 *         NULL on unsuccessful
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
