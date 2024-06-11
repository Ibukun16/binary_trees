#include "binary_trees.h"

/**
 * binary_tree_is_avl - A function that checks if a binary tree
 *			is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 for valid AVL Tree, and 0 for otherwise or NULL tree.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (avl_check_helper_func(tree, INT_MIN, INT_MAX));
}

/**
 * avl_check_helper_func - A helper function to check if binary tree is avl.
 * @tree: A pointer to the root node of the tree.
 * @low: The value of the smallest node on the tree so far checked.
 * @high: The value of the largest node on the tree so far checked.
 *
 * Return: 1 for a valid AVL tree or 0 for otherwise.
 */
int avl_check_helper_func(const binary_tree_t *tree, int low, int high)
{
	int left_path, rght_path;

	if (!tree)
		return (1);
	if (tree->n < low || tree->n > high)
		return (0);
	left_path = tree->left ? 1 + bin_tree_height(tree->left) : 0;
	rght_path = tree->right ? 1 + bin_tree_height(tree->right) : 0;
	if (abs(left_path - rght_path) > 1)
		return (0);
	return (avl_check_helper_func(tree->left, low, tree->n - 1) &&
		avl_check_helper_func(tree->right, tree->n + 1, high));
}

/**
 * bin_tree_height - A function that measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree or 0 if tree is NULL.
 */
size_t bin_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, rght_h = 0;

	if (!tree)
		return (0);
	left_h = tree->left ? 1 + bin_tree_height(tree->left) : 0;
	rght_h = tree->right ? 1 + bin_tree_height(tree->right) : 0;
	return (left_h > rght_h ? left_h : rght_h);
}
