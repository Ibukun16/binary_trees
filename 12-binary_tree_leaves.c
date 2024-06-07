#include "binary_trees.h"
/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 *
 * Description: NULL pointer is not a leaf
 *
 * Return: integer, else 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count += (!tree->left && !tree->right) ? 1 : 0;
		count += binary_tree_leaves(tree->left);
		count += binary_tree_leaves(tree->right);
	}
	return (count);
}
