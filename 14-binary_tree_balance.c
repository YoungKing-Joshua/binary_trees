#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL return 0, else return balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL function must return 0, else return height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, n = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		n = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((i > n) ? i : n);
	}
	return (0);
}
