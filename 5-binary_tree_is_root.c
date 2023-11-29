#include "binary_trees.h"

/**
 * binary_tree_is_root - Is root.
 * @p: Pointer.
 *
 * Return: no error - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *p)
{
	if (p == NULL || p->parent != NULL)
		return (0);

	return (1);
}
