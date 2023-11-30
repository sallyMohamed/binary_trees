#include "binary_trees.h"

/**
 * binary_tree_postorder - Post-order Our binary TREE.
 * @p: Pointer.
 * @pf: Function.
 */
void binary_tree_postorder(const binary_tree_t *p, void (*pf)(int))
{
	if (p && pf)
	{
		binary_tree_postorder(p->left, pf);
		binary_tree_postorder(p->right, pf);
		pf(p->n);
	}
}
