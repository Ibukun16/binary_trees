#include "binary_trees.h"

/**
 * binary_tree_ancestor - A function that finds the lowest
 *			common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes
 *		or NULL if no common ancestor is found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	size_t first_d, second_d;

	while (!first || !second)
		return (NULL);
	first_d = binary_tree_depth(first);
	second_d = binary_tree_depth(second);

	while  (first_d > second_d)
	{
		first = first->parent;
		first_d--;
	}
	while (second_d > first_d)
	{
		second = second->parent;
		second_d--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - A fnction that measures the depth of a
 *			node in a binary tree.
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: depth of the node or 0 if tree is NULL;
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}
	return (d);
}
