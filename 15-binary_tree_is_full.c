#include "binary_trees.h"

/**
 * is_full_recursive - Recursive.
 * @p: Pointer.
 *
 * Return:  0 Else 1.
 */
int is_full_recursive(const binary_tree_t *p)
{
	if (p != NULL)
	{
		if ((p->left != NULL && p->right == NULL) ||
		    (p->left == NULL && p->right != NULL) ||
		    is_full_recursive(p->left) == 0 ||
		    is_full_recursive(p->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Is full.
 * @p: Pointer.
 *
 * Return: NULL  0 ,Else 1.
 */
int binary_tree_is_full(const binary_tree_t *p)
{
	if (p == NULL)
		return (0);
	return (is_full_recursive(p));
}
