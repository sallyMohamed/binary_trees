#include "binary_trees.h"

/**
 * binary_tree_size - Size of a binary tree.
 * @p: Pointer.
 *
 * Return: Size of Our Binary tree.
 */
size_t binary_tree_size(const binary_tree_t *p)
{
	size_t size_p = 0;

	if (p)
	{
		size_p += 1;
		size_p += binary_tree_size(p->left);
		size_p += binary_tree_size(p->right);
	}
	return (size_p);
}
