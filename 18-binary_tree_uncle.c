#include "binary_trees.h"

/**
 * binary_tree_uncle - Uncle.
 * @p: pointer.
 *
 * Return: NULL ,Else Pointer to UncleNode.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *p)
{
	if (p == NULL ||
	    p->parent == NULL ||
	    p->parent->parent == NULL)
		return (NULL);
	if (p->parent->parent->left == p->parent)
		return (p->parent->parent->right);
	return (p->parent->parent->left);
}
