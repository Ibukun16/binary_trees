#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node.
 *	NULL if node is NULL or parent is Null,
 *	NULL if node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
