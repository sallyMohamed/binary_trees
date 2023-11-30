#include "binary_trees.h"

/**
 * binary_tree_balance - Balance.
 * @p: Pointer.
 *
 * Return: NULL -  0, Else return balance.
 */
int binary_tree_balance(const binary_tree_t *p)
{
	if (p)
		return (binary_tree_height(p->left) - binary_tree_height(p->right));

	return (0);
}

/**
 * binary_tree_height - Height.
 * @p: PointeR.
 *
 * Return: NULL - 0, Else return height.
 */
size_t binary_tree_height(const binary_tree_t *p)
{
	if (p)
	{
		size_t p_l = 0, p_r = 0;

		p_l = p->left ? 1 + binary_tree_height(p->left) : 1;
		p_r = p->right ? 1 + binary_tree_height(p->right) : 1;
		return ((p_l > p_r) ? p_l : p_r);
	}
	return (0);
}
