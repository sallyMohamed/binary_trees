#include "binary_trees.h"

/**
* binary_tree_rotate_right - Function that right-rotates a binary tree.
* @Tree: Pointer to the root node of the tree to rotate.
* Return: A pointer to the new root node after rotation.
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *Tree)
{
binary_tree_t *Pivot, *Temp;

if (Tree == NULL || Tree->left == NULL)
return (NULL);

Pivot = Tree->left;
Temp = Pivot->right;
Pivot->right = Tree;
Tree->left = Temp;
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
