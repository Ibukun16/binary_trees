#include "binary_trees.h"

/**
 * binary_tree_levelorder - A function that goes through a
 *			binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Result: void
 *	If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (!tree || !func)
		return;
	head = tail = create_node((binary_tree_t *)tree);

	if (!head)
		return;
	while (head)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - A function that create a new level order queue node
 * @node: A pointer to the binary tree node that hold the new node.
 *
 * Return: A pointer to the new node else nothing.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *newnode;

	newnode = malloc(sizeof(levelorder_queue_t));
	if (!newnode)
		return (NULL);

	newnode->node = node;
	newnode->next = NULL;
	return (newnode);
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *		pushes its childreen into a levelorder_queue_t queue.
 * @node: The binary tree node to push and print.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: If malloc fails, exit with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *newnode;

	func(node->n);
	if (node->left)
	{
		newnode = create_node(node->left);
		if (!newnode)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newnode;
		*tail = newnode;
	}
	if (node->right)
	{
		newnode = create_node(node->right);
		if (!newnode)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newnode;
		*tail = newnode;
	}
}

/**
 * free_queue - A function that frees a level order queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *buf;

	while (head)
	{
		buf = head->next;
		free(head);
		head = buf;
	}
}

/**
 * pop - A function that pops the head of a levelorder_queue_t queue.
 *
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *hold;

	hold = (*head)->next;
	free(*head);
	*head = hold;
}
