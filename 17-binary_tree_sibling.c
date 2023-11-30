#include "binary_trees.h"

/**
 * binary_tree_sibling - Sibling
 * @p: Pointer.
 *
 * Return: NULL - NOSibling ,Else pointer TOSibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *p)
{
	if (p == NULL || p->parent == NULL)
		return (NULL);
	if (p->parent->left == p)
		return (p->parent->right);
	return (p->parent->left);
}
