#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that insert a node as
 *			the left-child of a parent node.
 * @parent: A pointer to the parent node to insert the left child.
 * @value: The value to store in the new node.
 *
 * Description: If parent already has a left-child, the new node
 *		takes its place and the old left-child is set as
 *		the left-child of the new node whil the new node
 *		becomes the parent of the old left-child.
 *
 * Return: A pointer to the created node, or NULL if it fails
 *	or parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;
	return (new);
}
