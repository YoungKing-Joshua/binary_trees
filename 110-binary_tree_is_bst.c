#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if binary tree is a valid binary search tree
 *
 * @tree: Pointer to the root node of the tree to check
 * @lo: The value of the smallest node visited so far
 * @hi: The value of the largest node visited so far
 *
 * Return: When the tree is a valid BST returns 1, else return 0.
 */

int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if binary tree is a valid binary search tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: returns 1 if tree is a valid BST, and 0 elsewise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
