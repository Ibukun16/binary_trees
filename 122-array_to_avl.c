#include "binary_trees.h"

/**
 * array_to_avl - A function that builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created AVL tree or NULL
 *	if it fails. If value of the array already exist, then ignore.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int idx = 0;
	avl_t *tree = NULL;

	while (idx < size)
	{
		avl_insert(&tree, array[idx]);
		idx++;
	}
	return (tree);
}
