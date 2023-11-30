#include "binary_trees.h"

/**
 * binary_tree_preorder - Pre-order BINARY TREE.
 * @p: Pointer.
 * @pf: Function.
 */
void binary_tree_preorder(const binary_tree_t *p, void (*pf)(int))
{
	if (p && pf)
	{
		pf(p->n);
		binary_tree_preorder(p->left, pf);
		binary_tree_preorder(p->right, pf);
	}
}
