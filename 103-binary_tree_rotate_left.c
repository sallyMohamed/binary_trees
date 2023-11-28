#include "binary_trees.h"

/**
* binary_tree_rotate_left - function that Left-rotates a binary tree.
* @Tree: Pointer to the root node of the tree to rotate.
* Return: Pointer to the new root node after rotation.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *Tree)
{
binary_tree_t *Pivot, *Temp;

if (Tree == NULL || Tree->right == NULL)
return (NULL);

Pivot = Tree->right;
Temp = Pivot->left;
Pivot->left = Tree;
Tree->right = Temp;
if (Temp != NULL)
Temp->parent = Tree;
Temp = Tree->parent;
Tree->parent = Pivot;
Pivot->parent = Temp;
if (Temp != NULL)
{
if (Temp->left == Tree)
Temp->left = Pivot;
else
Temp->right = Pivot;
}
return (Pivot);
}
