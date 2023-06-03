
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates binary tree
 *
 * @tree: Pointer to root node of the tree to rotate.
 *
 * Return: Pointer to new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *piv, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	piv = tree->right;
	tmp = piv->left;
	piv->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = piv;
	piv->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = piv;
		else
			tmp->right = piv;
	}

	return (piv);
}
