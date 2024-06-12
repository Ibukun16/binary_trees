#include "binary_trees.h"

/**
 * heap_insert - A function that inserts a value in Max Binary Heap.
 * @root: A double pointer to the rrot node of the heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Description: If the address stored in root is NULL, the created
 *		node becomes the root. Max Heap ordering must be
 *		respected. Maximum of 6 functions in a file is allowed.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *newnode, *spin;
	int num, sub, bit, rank, buf;

	if (!root)
		return (NULL);
	/** Create a root node if it does not exist **/
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	num = binary_tree_size(tree);
	for (rank = 0, sub = 1; num >= sub; sub *= 2, rank++)
		num -= sub;
	for (bit = 1 << (rank - 1); bit != 1; bit >>= 1)
		tree = num & bit ? tree->right : tree->left;

	newnode = binary_tree_node(tree, value);
	num & 1 ? (tree->right = newnode) : (tree->left = newnode);

	spin = newnode;
	for (; spin->parent && (spin->n > spin->parent->n); spin = spin->parent)
	{
		buf = spin->n;
		spin->n = spin->parent->n;
		spin->parent->n = buf;
		newnode = newnode->parent;
	}
	return (newnode);
}

/**
 * binary_tree_size - A function that measures the size of a binary tree.
 * @tree: A pointer to the root node of the binary tree to measure.
 *
 * Return: The size of the binary tree, else 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}
