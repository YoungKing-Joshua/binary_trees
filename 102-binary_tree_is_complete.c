#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates new levelorder_queue_t node
 *
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If error occurs, NULL.
 *         Else, a pointer to the new node
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
 * free_queue - Frees levelorder_queue_t queue
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
 * push - Pushes node to the back of levelorder_queue_t queue
 *
 * @node: The binary tree node to print and push
 * @head: Double pointer to the head of the queue
 * @tail: Double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with status code of 1.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_n;

	new_n = create_node(node);
	if (new_n == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_n;
	*tail = new_n;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * 
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
