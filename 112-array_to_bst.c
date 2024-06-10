#include "binary_trees.h"

/**
 * array_to_bst - A function that builds a Binary Search Tree
 *			from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Description: If value of the array already exist in the tree, ignore.
 *
 * Return: NULL for failure else,
 *		a pointer to to the root node of the created BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int idx = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);

	while (idx < size)
	{
		bst_insert(&root, array[idx]);
		idx++;
	}
	return (root);
}
