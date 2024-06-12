#include "binary_trees.h"

/**
 * heap_to_sorted_array - A function that converts a Binary
 *			Max Heap to a sorted array of integers.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 *  Return: An array sorted in descending order.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL, c = 0;

	if (!heap || !size)
		return (NULL);
	*size = bin_tree_size(heap) + 1;
	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);
	while (heap)
	{
		array[c] = heap_extract(&heap);
		c++;
	}
	return (array);
}

/**
 * bin_tree_size - A function that measures and
 *			returns the binary tree height.
 * @tree: A pointer to the root node of the binary tree to measure.
 *
 * Return: Height of the binary tree or 0 if tree is NULL.
 */
size_t bin_tree_size(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);
	if (tree->left)
		l = 1 + bin_tree_size(tree->left);
	if (tree->right)
		r = 1 + bin_tree_size(tree->right);
	return (l + r);
}
