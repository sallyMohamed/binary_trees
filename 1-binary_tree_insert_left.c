#include "binary_trees.h"

/**
 * binary_tree_insert_left - Left-child ofbinary tree.
 * @pointer: Pointer.
 * @val: ValuE.
 *
 * Return: NULL orError.
 *         OR Pointer to the new node.
 *
 * Description: New node place.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *pointer, int val)
{
	binary_tree_t *new_node;

	if (pointer == NULL)
		return (NULL);

	new_node = binary_tree_node(pointer, val);
	if (new_node == NULL)
		return (NULL);

	if (pointer->left != NULL)
	{
		new_node->left = pointer->left;
		pointer->left->parent = new_node;
	}
	pointer->left = new_node;

	return (new_node);
}
