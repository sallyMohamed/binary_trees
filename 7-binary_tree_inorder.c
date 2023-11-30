#include "binary_trees.h"

/**
 * binary_tree_inorder - In-order Our binary tree.
 * @p: Pointer.
 * @pf: Function.
 */
void binary_tree_inorder(const binary_tree_t *p, void (*pf)(int))
{
	if (p && pf)
	{
		binary_tree_inorder(p->left, pf);
		pf(p->n);
		binary_tree_inorder(p->right, pf);
	}
}
