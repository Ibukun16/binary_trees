#include "binary_trees.h"

/**
 * binary_tree_is_complete - A function that checks if a binary
 *				tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 for success, else 0 for failure or if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t n;

	if (!tree)
		return (0);
	n = binary_tree_size(tree);
	return (helper_func_complete(tree, 0, n));
}

/**
 * helper_func_complete - A helper function to binary_tree_is_complete
 * @tree: A pointer to the root node of thetree to check.
 * @idx: Index to the node to check.
 * @n: The number of nodes in the tree
 *
 * Return: 1 for success, else 0 for failure or if tree is NULL.
 */
int helper_func_complete(const binary_tree_t *tree, size_t idx, size_t n)
{
	if (!tree)
		return (1);
	if (idx >= n)
		return (0);
	return (helper_func_complete(tree->left, 2 * idx + 1, n) &&
		helper_func_complete(tree->right, 2 * idx + 2, n));
}

/**
 * binary_tree_size - A function that measures the size of a binary tree.
 * @tree: A pointer to the node of the tree to measure its size
 *
 * Return: size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}
