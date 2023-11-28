#include "binary_trees.h"

/**
* Bst_Insert - It inserts a value in a Binary Search Tree.
* @Tree: Double pointer to the root node of the BST to insert the value.
* @Value: Value to store in the node to be inserted.
* Return: A pointer to the created node, or NULL on failure.
*/
bst_t *Bst_Insert(bst_t **Tree, int Value)
{
bst_t *Curr, *New;

if (Tree != NULL)
{
Curr = *Tree;

if (Curr == NULL)
{
New = binary_tree_node(Curr, Value);
if (New == NULL)
return (NULL);
return (*Tree = New);
}

if (Value < Curr->n) /* insert in left subtree */
{
if (Curr->left != NULL)
return (Bst_Insert(&Curr->left, Value));

New = binary_tree_node(Curr, Value);
if (New == NULL)
return (NULL);
return (Curr->left = New);
}
if (Value > Curr->n) /* insert in right subtree */
{
if (Curr->right != NULL)
return (Bst_Insert(&Curr->right, Value));

New = binary_tree_node(Curr, Value);
if (New == NULL)
return (NULL);
return (Curr->right = New);
}
}
return (NULL);
}