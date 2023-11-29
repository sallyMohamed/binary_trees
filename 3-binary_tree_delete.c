#include "binary_trees.h"

/**
 * binary_tree_delete - Delete.
 * @del: delete.
 */
void binary_tree_delete(binary_tree_t *del)
{
	if (del != NULL)
	{
		binary_tree_delete(del->left);
		binary_tree_delete(del->right);
		free(del);
	}
}
