#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of binary tree
 * 
 * @tree: Pointer to root node of tree to measure the height
 *
 * Return: If tree is NULL, your function must return zero(0), else return height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, n = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		n = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((i > n) ? i : n);
	}
	return (0);
}
