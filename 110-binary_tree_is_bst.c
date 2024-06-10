#include "binary_trees.h"

/**
 * binary_tree_is_bst - A function that checks if a binary tree
 *			is a valid Binary Search Tree.
 * @tree: a pointer to the rot node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 for otherwise or if tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_check_helper_func(tree, INT_MIN, INT_MAX));
}

/**
 * bst_check_helper_func - A helper function that checks if a
 *			binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The lower boundary of the nodes to check
 * @high: The upper boundary of the nodes to check
 *
 * Return: 1 if tree is a valid BST or 0 for otherwise.
 */
int bst_check_helper_func(const binary_tree_t *tree, int low, int high)
{
	if (!tree)
		return (1);
	if (tree->n < low || tree->n > high)
		return (0);
	return (bst_check_helper_func(tree->left, low, tree->n - 1)
		&& bst_check_helper_func(tree->right, tree->n + 1, high));
}
