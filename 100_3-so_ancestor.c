#include "binary_trees.h"

/**
 * binary_trees_ancestor - Lowest nodes.
 * @f: First node.
 * @s: Second node.
 *
 * Return: NULL  Else return Ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *f,
		const binary_tree_t *s)
{
	binary_tree_t *p_mom, *p_pop;

	if (!f || !s)
		return (NULL);
	if (f == s)
		return ((binary_tree_t *)f);

	p_mom = f->parent, p_pop = s->parent;
	if (f == p_pop || !p_mom || (!p_mom->parent && p_pop))
		return (binary_trees_ancestor(f, p_pop));
	else if (p_mom == s || !p_pop || (!p_pop->parent && p_mom))
		return (binary_trees_ancestor(p_mom, s));
	return (binary_trees_ancestor(p_mom, p_pop));
}
