#include "binary_trees.h"

/**
 * avl_remove - A  function that removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree to remove the node
 * @value: The value to remove from the tree.
 *
 * Description: Locate a node containing a given value, remove the
 *		value and free the node. If node has 2 children,
 *		replace node with its first in-order successor.
 *		After deletion of desire node, AVL tree must rebalance.
 * Return: A pointer to the new root node of the tree after removing
 *		the desired value and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_avl = (avl_t *) bst_remove((bst_t *) root, value);

	if (!root_avl)
		return (NULL);
	get_balance_factor(&root_avl);

	return (root_avl);
}

/**
 * bst_remove - A function that removes a node from a BST tree.
 * @root: A pointer to the root node of the tree to remove from.
 * @value: The value to remove from the node.
 *
 * Return: The modified tree after the removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_on_condition(root);
		if (type)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * remove_on_condition - A function that removes a node based on its children.
 * @root: A pointer to the root node to remove from the tree.
 *
 * Return: 0 if no children else any other value.
 */
int remove_on_condition(bst_t *root)
{
	int value_new = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		value_new = successor(root->right);
		root->n = value_new;
		return (value_new);
	}
}

/**
 * successor - A function that get the next successor
 *		i.e the min node in the right subtree.
 * @node: A pointer to the root node to checkfor successor.
 *
 * Return: The minimum value on the tree.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (!node)
		return (0);
	left = successor(node->left);
	if (left == 0)
		return (node->n);
	return (left);
}

/**
 * get_balance_factor - A function that measures balance factor of an AVL.
 * @tree: Tree to go through.
 *
 * Return: The balance factor.
 */
void get_balance_factor(avl_t **tree)
{
	int binval;

	if (!tree || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	get_balance_factor(&(*tree)->left);
	get_balance_factor(&(*tree)->right);
	binval = binary_tree_balance((const binary_tree_t *)*tree);
	if (binval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (binval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
