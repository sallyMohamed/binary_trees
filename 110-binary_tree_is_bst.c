#include "binary_trees.h"
#include "limits.h"

/**
* Is_Bst_Helper - Function checks a binary tree is a valid binary search tree
* @Tree: Pointer to the root node of the tree to check.
* @Lo: Value of the smallest node visited thus far.
* @Hi: Value of the largest node visited this far.
* Return: If the tree is a valid BST, 1, otherwise, 0.
*/
int Is_Bst_Helper(const binary_tree_t *Tree, int Lo, int Hi)
{
if (Tree != NULL)
{
if (Tree->n < Lo || Tree->n > Hi)
return (0);
return (Is_Bst_Helper(Tree->left, Lo, Tree->n - 1) &&
Is_Bst_Helper(Tree->right, Tree->n + 1, Hi));
}
return (1);
}

/**
* binary_tree_is_bst - It checks a binary tree is a valid binary search tree
* @Tree: Pointer to the root node of the tree to check.
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *Tree)
{
if (Tree == NULL)
return (0);
return (Is_Bst_Helper(Tree, INT_MIN, INT_MAX));
}
