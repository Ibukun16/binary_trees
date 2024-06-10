#include "binary_trees.h"

/**
 * bst_remove - A function that removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the tree where node is to be removed.
 * @value: The value to remove from the tree.
 *
 * Description: Once located, the node containing the value equal to
 *		given value must be removed and freed.
 *		If the node to be deleted has two children, it must
 *		be replaced with its first in-order successor.
 * Return: A pointer to the new root node of the tree after
 *		removing given value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (recursive_remove(root, root, value));
}

/**
 * recursive_remove - A function that removes a node from binary
 *			search tree by recursion.
 * @root: A pointer to the root node of the BST to remove a node fom.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node upon deletion.
 */
bst_t *recursive_remove(bst_t *root, bst_t *node, int value)
{
	if (!node)
		return (NULL);
	if (node->n == value)
		return (delete_node(root, node));
	if (node->n > value)
		return (recursive_remove(root, node->left, value));
	return (recursive_remove(root, node->right, value));
}

/**
 * delete_node - A function that deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node upon deletion.
 */
bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/** A case of no children or right child only **/
	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/** A case of left child only **/
	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/** Two children **/
	successor = in_order_successor(node->right);
	node->n = successor->n;
	return (delete_node(root, successor));
}

/**
 * in_order_successor -  A function that return the minimum
 *			value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * Return: The minimum value in @tree.
 */
bst_t *in_order_successor(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

