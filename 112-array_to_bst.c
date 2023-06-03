#include "binary_trees.h"

/**
 * array_to_bst - Builds binary search tree from array
 *
 * @array: Pointer to first element of the array to be converted.
 * @size: Number of elements in @array.
 *
 * Return: A pointer to root node of the created BST or NULL upon failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *s_tree = NULL;
	size_t k, l;

	if (array == NULL)
		return (NULL);

	for (k = 0; k < size; k++)
	{
		for (l = 0; l < k; l++)
		{
			if (array[l] == array[k])
				break;
		}
		if (l == k)
		{
			if (bst_insert(&s_tree, array[k]) == NULL)
				return (NULL);
		}
	}

	return (s_tree);
}
