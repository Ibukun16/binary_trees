#include "binary_trees.h"

/**
 * heap_extract - A function that extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of heap.
 *
 * Description: The root node must be freed and replaced with the
 *		last level-order node of the heap.
 *		Once replaced, the heap must be rebuilt if necessary.
 * Return: The value stored in the root node, else 0 if it fails.
 */
int heap_extract(heap_t **root)
{
	int val, height;

	heap_t *node;


	if (!root || !*root)
		return (0);
	val = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		*root = NULL;
		free(*root);
		return (val);
	}
	height = height_tree(*root);
	preorder_func(*root, &node, height);
	(*root)->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	max_val(*root);
	return (val);
}

/**
 * preorder_func - A function that traverse a binary tree by preorder.
 * @tree: A pointer to the root of the tree.
 * @node: The last note in the traverse.
 * @height: The height of the tree.
 *
 * Return: void.
 */
void preorder_func(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	preorder_func(tree->left, node, height);
	preorder_func(tree->right, node, height);
}

/**
 * max_val - A function that finds the node with the maximum
 *		value in a tree.
 * @root: A pointer to the root of the binary heap with the maximum value.
 *
 * Return: void.
 */
void max_val(heap_t *root)
{
	int val;
	heap_t *hold, *temp;

	if (!root)
		return;
	hold = root;
	while (1)
	{
		if (!hold->left)
			break;
		if (!hold->right)
			temp = hold->left;
		else
		{
			if (hold->left->n > hold->right->n)
				temp = hold->left;
			else
				temp = hold->right;
		}
		if (hold->n > temp->n)
			break;
		val = hold->n;
		hold->n = temp->n;
		temp->n = val;
		hold = temp;
	}
}

/**
 * height_tree - A function that measures the height of the binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: Height or 0 if tree is NULL.
 */
size_t height_tree(const heap_t *tree)
{
	size_t left_h = 0, rght_h = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_h = 1 + height_tree(tree->left);
	if (tree->right)
		rght_h = 1 + height_tree(tree->right);
	if (left_h > rght_h)
		return (left_h);
	return (rght_h);
}
