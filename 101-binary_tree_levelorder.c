#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates new levelorder_queue_t node
 *
 * @node: Binary tree node for the new node to contain
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_n;

	new_n = malloc(sizeof(levelorder_queue_t));
	if (new_n == NULL)
		return (NULL);

	new_n->node = node;
	new_n->next = NULL;

	return (new_n);
}

/**
 * free_queue - Frees the levelorder_queue_t queue
 * 
 * @head: Pointer to the head of the queue.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - Runs function on given binary tree node and
 *             pushes its children into a levelorder_queue_t queue
 *
 * @node: The binary tree node to print and push
 * @head: Double pointer to the head of the queue.
 * @tail: Double pointer to the tail of the queue
 * @func: Pointer to the function to call on node
 *
 * Description: Upon malloc failure, exits with a status code of 1
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_n;

	func(node->n);
	if (node->left != NULL)
	{
		new_n = create_node(node->left);
		if (new_n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_n;
		*tail = new_n;
	}
	if (node->right != NULL)
	{
		new_n = create_node(node->right);
		if (new_n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_n;
		*tail = new_n;
	}
}

/**
 * pop - Pops the head of levelorder_queue_t queue.
 *
 * @head: Double pointer to the head of the queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
