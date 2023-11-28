#include "binary_trees.h"

/**
 * bst_search - It searches for a value in a binary search tree.
 * @Tree: Pointer to the root node of the BST to search.
 * @Value: Value to search for in the BST.
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *Tree, int Value)
{
if (Tree != NULL)
{
if (Tree->n == Value)
return ((bst_t *)Tree);
if (Tree->n > Value)
return (bst_search(Tree->left, Value));
return (bst_search(Tree->right, Value));
}
return (NULL);
}
