#include "binary_trees.h"

/**
 * sorted_array_to_avl - A function that builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Description: Assume no duplicate value in the array, no rotation
 *		allowed. Only 2 functions are allowed in a file.
 *
 * Return: A pointer to the root node of the created AVL tree else
 *		NULL for failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (sort_func(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * sort_func - A function that creates the tree using half element
 *		of the array.
 * @parent: A pointer to the parent of the node to be created.
 * @array: The sorted array.
 * @begin: The beginning of the array where it starts.
 * @end: the end position of the array.
 *
 * Return: The created tree.
 */
avl_t *sort_func(avl_t *parent, int *array, int begin, int end)
{
	avl_t *root;
	binary_tree_t *tmp;
	int p = 0;

	if (begin <= end)
	{
		p = (begin + end) / 2;
		tmp = binary_tree_node((binary_tree_t *)parent, array[p]);
		if (tmp == NULL)
			return (NULL);
		root = (avl_t *)tmp;
		root->left = sort_func(root, array, begin, p - 1);
		root->right = sort_func(root, array, p + 1, end);
		return (root);
	}
	return (NULL);
}

