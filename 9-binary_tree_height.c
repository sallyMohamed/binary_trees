#include "binary_trees.h"

/**
 * binary_tree_height - Height Binary tree.
 * @p: Pointer.
 *
 * Return: NULL - return 0
 *         Else return Value of height.
 */
size_t binary_tree_height(const binary_tree_t *p)
{
	if (p)
	{
		size_t l_p = 0, r_p = 0;

		l_p = p->left ? 1 + binary_tree_height(p->left) : 0;
		r_p = p->right ? 1 + binary_tree_height(p->right) : 0;
		return ((l_p > r_p) ? l_p : r_p);
	}
	return (0);
}
