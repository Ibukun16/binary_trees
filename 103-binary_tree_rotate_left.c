#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that performs a
 *				left-rotation on a tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *turning;

	if (!tree || !tree->right)
		return (NULL);
	turning = tree->right;
	tree->right = turning->left;
	if (turning->left)
		turning->left->parent = tree;
	turning->left = tree;
	turning->parent = tree->parent;
	tree->parent = turning;
	return (turning);
}
