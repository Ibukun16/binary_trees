#include "binary_trees.h"

/**
 * binary_tree_is_root - A function that checks if a node is a root.
 * @node: A poinyter to the node to check
 *
 * Return: 1 if a node is a root, or if it is not or if node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
		return (1);
	return (0);
}
