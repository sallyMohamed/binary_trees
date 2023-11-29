#include "binary_trees.h"

/**
 * binary_tree_insert_right - Right-child In a binary tree.
 * @p: Pointer.
 * @v: Value.
 *
 * Return: NULL or Error occurs ORpointer tOnew node.
 *
 * Description: Right-chilD place.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *p, int v)
{
	binary_tree_t *new_node;

	if (p == NULL)
		return (NULL);

	new_node = binary_tree_node(p, v);
	if (new_node == NULL)
		return (NULL);

	if (p->right != NULL)
	{
		new_node->right = p->right;
		p->right->parent = new_node;
	}
	p->right = new_node;

	return (new_node);
}
