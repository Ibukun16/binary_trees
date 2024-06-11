#include "binary_trees.h"

/**
 * avl_insert - A function that inserts a value in an AVL Tree.
 * @tree: A double pointer to the root node of the AVL tree to insert value.
 *@value: The value to store in the node to be inserted.
 * Description: If address strored in tree is NULL,
 *		the created node becomes the root node.
 *
 * Return: A balanced AVL Tree.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	recursive_insert_node(tree, *tree, &new, value);
	return (new);
}

/**
 * recursive_insert_node - A function that insert node in an
 *				AVL tree by recursion.
 * @tree: A double pointer to the root node of the AVL tree structure.
 * @parent: The parent node of the AVL tree structure.
 * @new: A double pointer to the inserted node to the AVL tree.
 * @newvalue: The value to add to the insert node of the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL for failure.
 */
avl_t *recursive_insert_node(avl_t **tree, avl_t *parent,
				avl_t **new, int newvalue)
{
	int binval;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, newvalue));
	if ((*tree)->n > newvalue)
	{
		(*tree)->left = recursive_insert_node(&(*tree)->left,
						*tree, new, newvalue);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < newvalue)
	{
		(*tree)->right = recursive_insert_node(&(*tree)->right,
					*tree, new, newvalue);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	binval = binary_tree_balance(*tree);
	if (binval > 1 && (*tree)->left->n > newvalue)
		*tree = binary_tree_rotate_right(*tree);
	else if (binval > 1 && (*tree)->left->n < newvalue)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (binval < -1 && (*tree)->right->n < newvalue)
		*tree = binary_tree_rotate_left(*tree);
	else if (binval < -1 && (*tree)->right->n > newvalue)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);

}
