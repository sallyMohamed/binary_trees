#include "binary_trees.h"

/**
 * binary_tree_nodes - Nodes in our tree.
 * @p: Pointer.
 *
 * Return: NULL - 0, Else return count.
 */
size_t binary_tree_nodes(const binary_tree_t *p)
{
	size_t p_nodes = 0;

	if (p)
	{
		p_nodes += (p->left || p->right) ? 1 : 0;
		p_nodes += binary_tree_nodes(p->left);
		p_nodes += binary_tree_nodes(p->right);
	}
	return (p_nodes);
}
