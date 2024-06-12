#include "binary_trees.h"

/**
 * binary_tree_is_heap - A function that checks if a binary
 *			tree is valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if it is a valid Max Binary Heap, and 0 otherwise or
 *		if tree is NULL.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (heap_checker(tree));
}

/**
 * heap_checker - A helper function that checks if a
 *			binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap or if tree is NULL,
 *		else return 0.
 */
int heap_checker(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->n > tree->parent->n)
		return (0);
	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (heap_checker(tree->left) &&
		heap_checker(tree->right));
}

/**
 * binary_tree_is_complete - A function that checks if a
 *				binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, else 0 if the tree
 *		is incomplete or is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	return (helper_func_complete(tree, 0, size));
}

/**
 * helper_func_complete - A helper function that checks if a
 *				binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @idx: Index to the node to check.
 * @n: The number of nodes in the binary tree to check.
 *
 * Return: 1 if tree is complate else 0 if tree is incomplete or NULL.
 */
int helper_func_complete(const binary_tree_t *tree, size_t idx, size_t n)
{
	if (!tree)
		return (1);
	if (idx >= n)
		return (0);
	return (helper_func_complete(tree->left, (2 * idx) + 1, n) &&
		helper_func_complete(tree->right, (2 * idx) + 2, n));
}

/**
 * binary_tree_size - A function that measures the size of the binary tree.
 * @tree: A pointer to the root node of the tree to measure its size.
 *
 * Return: The size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}
