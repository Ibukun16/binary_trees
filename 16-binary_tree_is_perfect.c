#include "binary_trees.h"

/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree exist and is perfect else return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0;
	size_t size = 0;
	size_t layer = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	h = binary_tree_height(tree);
	size = binary_tree_size(tree);
	layer = (size_t)layer_recursive_func(2, h + 1);
	return (layer - 1 == size);
}
/**
 * layer_recursive_func - A function that returns the
 *			exponential of l raise to power n.
 * @l: The integer to get its exponential.
 * @n: The exponential power
 *
 * Return: The exponential result.
 */
int layer_recursive_func(int l, int n)
{
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	else
		return (l * layer_recursive_func(l, n - 1));
}

/**
 * binary_tree_size - A function that measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure its size.
 *
 * Return: size of the tree, else 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
		return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
	return (0);
}

/**
 * binary_tree_height - A function that measures that height of a binary tree.
 * @tree:A pointer to the root node of the tree to measure its size.
 *
 * Return: The height of the tree else 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
