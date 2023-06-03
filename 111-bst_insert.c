#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 *
 * @tree: Double pointer to root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new_n;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new_n = binary_tree_node(curr, value);
			if (new_n == NULL)
				return (NULL);
			return (*tree = new_n);
		}

		if (value < curr->n)
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			new_n = binary_tree_node(curr, value);
			if (new_n == NULL)
				return (NULL);
			return (curr->left = new_n);
		}
		if (value > curr->n)
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			new_n = binary_tree_node(curr, value);
			if (new_n == NULL)
				return (NULL);
			return (curr->right = new_n);
		}
	}
	return (NULL);
}
