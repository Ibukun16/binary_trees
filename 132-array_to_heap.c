#include "binary_trees.h"

/**
 * array_to_heap - A pointer to the first element of the array to be converted.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created Binary Heap,
 *		else NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int idx = 0;
	heap_t *root = NULL;

	while (idx < size)
	{
		heap_insert(&root, array[idx]);
		idx++;
	}
	return (root);
}
