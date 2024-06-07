#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that insert a node as the
 *				right-child of another node in a tree
 * @parent: A pointer to the parent node to insert the right-child in
 * @value: The value to be stored in the new node
 *
 * Description: If parent already has a right-child, the new node
 *		takes its place, and the old right-child becomes the
 *		right-child of the new node.
 *
 * Return: A pointer to the new right node, or NULL if if fails or
 *		parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;
	return (new);
}
