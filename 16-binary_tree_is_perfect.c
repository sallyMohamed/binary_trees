#include "binary_trees.h"

/**
 * p_is_leaf - Is leaf.
 * @p_node: Pointer.
 *
 * Return: leaf 1 Else 0.
 */
unsigned char p_is_leaf(const binary_tree_t *p_node)
{
	return ((p_node->left == NULL && p_node->right == NULL) ? 1 : 0);
}

/**
 * p_depth - Depth .
 * @p: Pointer.
 * Return: Depth.
 */
size_t p_depth(const binary_tree_t *p)
{
	return (p->parent != NULL ? 1 + p_depth(p->parent) : 0);
}

/**
 * p_get_leaf - Get leaf.
 * @p: Pointer.
 *
 * Return: leaf.
 */
const binary_tree_t *p_get_leaf(const binary_tree_t *p)
{
	if (p_is_leaf(p) == 1)
		return (p);
	return (p->left ? p_get_leaf(p->left) : p_get_leaf(p->right));
}

/**
 * is_perfect_recursive - Recursive.
 * @p: Pointer.
 * @p_leaf_depth: Leaf Depth.
 * @p_level: Level.
 *
 * Return: tree 1 Else 0.
 */
int is_perfect_recursive(const binary_tree_t *p,
		size_t p_leaf_depth, size_t p_level)
{
	if (p_is_leaf(p))
		return (p_level == p_leaf_depth ? 1 : 0);
	if (p->left == NULL || p->right == NULL)
		return (0);
	return (is_perfect_recursive(p->left, p_leaf_depth, p_level + 1) &&
		is_perfect_recursive(p->right, p_leaf_depth, p_level + 1));
}

/**
 * binary_tree_is_perfect - IS Perfect.
 * @p: Pointer.
 *
 * Return: NULL  0 Else 1.
 */
int binary_tree_is_perfect(const binary_tree_t *p)
{
	if (p == NULL)
		return (0);
	return (is_perfect_recursive(p, p_depth(p_get_leaf(p)), 0));
}
