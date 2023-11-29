#include "binary_trees.h"

/**
* bal - It measures balance factor of a AVL
* @Tree: Tree to go through
* Return: balanced factor
*/
void bal(avl_t **Tree)
{
int Bval;

if (Tree == NULL || *Tree == NULL)
return;
if ((*Tree)->left == NULL && (*Tree)->right == NULL)
return;
bal(&(*Tree)->left);
bal(&(*Tree)->right);
Bval = binary_tree_balance((const binary_tree_t *)*Tree);
if (Bval > 1)
*Tree = binary_tree_rotate_right((binary_tree_t *)*Tree);
else if (Bval < -1)
*Tree = binary_tree_rotate_left((binary_tree_t *)*Tree);
}
/**
* successor - It get next successor i mean the min node in the right subtree
* @TheNode: Tree to check
* Return: the min value of this tree
*/
int successor(bst_t *TheNode)
{
int Left = 0;

if (TheNode == NULL)
{
return (0);
}
else
{
Left = successor(TheNode->left);
if (Left == 0)
{
return (TheNode->n);
}
return (Left);
}
}
/**
*remove_type - It's a function that removes a node depending of its children
*@Root: Node to remove
*Return: 0 if it has no children or other value if it has
*/
int remove_type(bst_t *Root)
{
int NewValue = 0;

if (!Root->left && !Root->right)
{
if (Root->parent->right == Root)
Root->parent->right = NULL;
else
Root->parent->left = NULL;
free(Root);
return (0);
}
else if ((!Root->left && Root->right) || (!Root->right && Root->left))
{
if (!Root->left)
{
if (Root->parent->right == Root)
Root->parent->right = Root->right;
else
Root->parent->left = Root->right;
Root->right->parent = Root->parent;
}
if (!Root->right)
{
if (Root->parent->right == Root)
Root->parent->right = Root->left;
else
Root->parent->left = Root->left;
Root->left->parent = Root->parent;
}
free(Root);
return (0);
}
else
{
NewValue = successor(Root->right);
Root->n = NewValue;
return (NewValue);
}
}
/**
* bst_remove - It remove a node from a BST tree
* @Root: Root of the tree
* @Value: Node with this value to remove
* Return: the tree changed
*/
bst_t *bst_remove(bst_t *Root, int Value)
{
int Type = 0;

if (Root == NULL)
return (NULL);
if (Value < Root->n)
bst_remove(Root->left, Value);
else if (Value > Root->n)
bst_remove(Root->right, Value);
else if (Value == Root->n)
{
Type = remove_type(Root);
if (Type != 0)
bst_remove(Root->right, Type);
}
else
return (NULL);
return (Root);
}

/**
* avl_remove - IT remove a node from a AVL tree
* @Root: Root of the tree
* @Value: Node with this value to remove
* Return: the tree changed
*/
avl_t *avl_remove(avl_t *Root, int Value)
{
avl_t *Root_A = (avl_t *) bst_remove((bst_t *) Root, Value);

if (Root_A == NULL)
return (NULL);
bal(&Root_A);
return (Root_A);
}

