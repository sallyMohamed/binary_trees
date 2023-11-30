#include "binary_trees.h"

size_t p_depth(const binary_tree_t *p);

/**
 * binary_trees_ancestor - Ancestor of nodes.
 * @f: First node.
 * @s: Second node.
 *
 * Return: NULL
 *         Else ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *f,
		const binary_tree_t *s)
{
	size_t f_depth, s_depth;

	if (f == NULL || s == NULL)
		return (NULL);
	if (f == s)
		return ((binary_tree_t *)f);
	if (f->parent == s->parent)
		return ((binary_tree_t *)f->parent);
	if (f == s->parent)
		return ((binary_tree_t *)f);
	if (f->parent == s)
		return ((binary_tree_t *)s);

	for (f_depth = p_depth(f); f_depth > 1; f_depth--)
		f = f->parent;
	for (s_depth = p_depth(s); s_depth > 1; s_depth--)
		s = s->parent;

	if (f == s)
		return ((binary_tree_t *)f);
	if (f->parent == s->parent)
		return ((binary_tree_t *)f->parent);
	if (f == s->parent)
		return ((binary_tree_t *)f);
	if (f->parent == s)
		return ((binary_tree_t *)s);
	else
		return (NULL);
}

/**
 * p_depth - Depth.
 * @p: Pointer.
 *
 * Return: NULL - 0, Else return Value of depth.
 */
size_t p_depth(const binary_tree_t *p)
{
	return ((p->parent != NULL) ? 1 + p_depth(p>parent) : 0);
}
