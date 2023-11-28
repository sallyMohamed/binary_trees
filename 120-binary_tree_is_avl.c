#include "binary_trees.h"
#include "limits.h"

size_t Height(const binary_tree_t *Tree);
int Is_Avl_Helper(const binary_tree_t *Tree, int Lo, int Hi);
int Binary_Tree_Is_Avl(const binary_tree_t *Tree);

/**
* Height - Function that measures the height of a binary tree.
* @Tree: Pointer to the root node of the tree to measure the height.
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t Height(const binary_tree_t *Tree)
{
if (Tree)
{
size_t L = 0, R = 0;

L = Tree->left ? 1 + Height(Tree->left) : 1;
R = Tree->right ? 1 + Height(Tree->right) : 1;
return ((l > r) ? l : r);
}
return (0);
}

/**
* is_avl_helper - It checks if a binary tree is a valid AVL tree.
* @Tree: Pointer to the root node of the tree to check.
* @Lo: Value of the smallest node visited thus far.
* @Hi: Value of the largest node visited this far.
* Return: If the tree is a valid AVL tree, 1, otherwise, 0.
*/
int Is_Avl_Helper(const binary_tree_t *Tree, int Lo, int Hi)
{
size_t Lhgt, Rhgt, Diff;

if (Tree != NULL)
{
if (Tree->n < Lo || Tree->n > Hi)
return (0);
Lhgt = Height(Tree->left);
Rhgt = Height(Tree->right);
Diff = Lhgt > Rhgt ? Lhgt - Rhgt : Rhgt - Lhgt;
if (Diff > 1)
return (0);
return (Is_Avl_Helper(Tree->left, Lo, Tree->n - 1) &&
Is_Avl_Helper(Tree->right, Tree->n + 1, Hi));
}
return (1);
}

/**
* Binary_Tree_Is_Avl - It checks if a binary tree is a valid AVL tree.
* @Tree: Pointer to the root node of the tree to check.
* Return: 1 if tree is a valid AVL tree, and 0 otherwise
*/
int Binary_Tree_Is_Avl(const binary_tree_t *Tree)
{
if (Tree == NULL)
return (0);
return (Is_Avl_Helper(Tree, INT_MIN, INT_MAX));
}
