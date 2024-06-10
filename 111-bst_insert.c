#include "binary_trees.h"

/**
 * bst_insert - A function that insert a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL, the created
 *		node becomes the root node. If value is already
 *		already present in the tree, then ignore.
 *
 * Return: A pointer to the created node or NULL in case of failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur = NULL, *sec = NULL, *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	cur = *tree;
	while (cur)
	{
		sec = cur;
		if (value < cur->n)
			cur = cur->left;
		else if (value > cur->n)
			cur = cur->right;
		else if (value == cur->n)
			return (NULL);
	}
	new = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = new;
	else if (value < sec->n)
	{
		sec->left = new;
		new->parent = sec;
	}
	else
	{
		sec->right = new;
		new->parent = sec;
	}
	return (new);
}
