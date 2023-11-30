#include "binary_trees.h"

/**
 * binary_tree_depth - Depth of Our binary tree.
 * @p: Pointer.
 *
 * Return: NULL - return 0
 *         Else return value of  depth.
 */
size_t binary_tree_depth(const binary_tree_t *p)
{
	return ((p && p->parent) ? 1 + binary_tree_depth(p->parent) : 0);
}
