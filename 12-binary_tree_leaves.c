#include "binary_trees.h"

/**
 * binary_tree_leaves - leaves of our binary tree.
 * @p: pointer.
 *
 * Return: Number.
 */
size_t binary_tree_leaves(const binary_tree_t *p)
{
	size_t p_leaves = 0;

	if (p)
	{
		p_leaves += (!p->left && !p->right) ? 1 : 0;
		p_leaves += binary_tree_leaves(p->left);
		p_leaves += binary_tree_leaves(p->right);
	}
	return (p_leaves);
}
