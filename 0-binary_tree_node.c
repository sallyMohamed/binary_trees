#include "binary_trees.h"

/**
 * binary_tree_node - Tree node.
 * @pointer: Pointer.
 * @val: Value.
 *
 * Return: NULL.
 *         Otherwise - PointerTothe new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *pointer, int val)
{
	binary_tree_t *n_node;

	n_node = malloc(sizeof(binary_tree_t));
	if (n_node == NULL)
		return (NULL);

	n_node->n = val;
	n_node->parent = pointer;
	n_node->left = NULL;
	n_node->right = NULL;

	return (n_node);
}
