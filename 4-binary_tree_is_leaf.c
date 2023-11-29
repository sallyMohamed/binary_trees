#include "binary_trees.h"

/**
 * binary_tree_is_leaf - leaf of a binary tree.
 * @p: Pointer.
 *
 * Return: leaf - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *p)
{
	if (p == NULL || p->left != NULL || p->right != NULL)
		return (0);

	return (1);
}
