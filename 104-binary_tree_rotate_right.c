#include "binary_trees.h"

/**
 * binary_tree_rotate_right - A function that performs a
 *				right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *turning;

	if (!tree || !tree->left)
		return (NULL);
	turning = tree->left;
	tree->left = turning->right;
	if (turning->right)
		turning->right->parent = tree;
	turning->right = tree;
	turning->parent = tree->parent;
	tree->parent = turning;
	return (turning);
}
