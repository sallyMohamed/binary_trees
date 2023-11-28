#include "binary_trees.h"

bst_t *inorder_successor(bst_t *Root);
bst_t *bst_delete(bst_t *Root, bst_t *TheNode);
bst_t *bst_remove_recursive(bst_t *Root, bst_t *TheNode, int Value);
bst_t *bst_remove(bst_t *Root, int Value);

/**
* inorder_successor - It returns the minimum value of a binary search tree.
* @Root: Pointer to the root node of the BST to search.
* Return: The minimum value in @tree.
*/
bst_t *inorder_successor(bst_t *Root)
{
while (Root->left != NULL)
Root = Root->left;
return (Root);
}

/**
* bst_delete - It deletes a node from a binary search tree.
* @Root: Pointer to the root node of the BST.
* @TheNode: Pointer to the node to delete from the BST.
* Return: A pointer to the new root node after deletion.
*/
bst_t *bst_delete(bst_t *Root, bst_t *TheNode)
{
bst_t *Parent = TheNode->Parent, *Successor = NULL;

/* No children or right-child only */
if (TheNode->left == NULL)
{
if (Parent != NULL && Parent->left == TheNode)
Parent->left = TheNode->right;
else if (Parent != NULL)
Parent->right = TheNode->right;
if (TheNode->right != NULL)
TheNode->right->Parent = Parent;
free(TheNode);
return (Parent == NULL ? TheNode->right : Root);
}

/* Left-child only */
if (TheNode->right == NULL)
{
if (Parent != NULL && Parent->left == TheNode)
Parent->left = TheNode->left;
else if (Parent != NULL)
Parent->right = TheNode->left;
if (TheNode->left != NULL)
TheNode->left->Parent = Parent;
free(TheNode);
return (Parent == NULL ? TheNode->left : Root);
}

/* Two children */
Successor = inorder_successor(TheNode->right);
TheNode->n = Successor->n;

return (bst_delete(Root, Successor));
}

/**
* bst_remove_recursive - It removes node from a binary search tree recursively
* @Root: Pointer to the root node of the BST to remove a node from.
* @TheNode: Pointer to the current node in the BST.
* @Value: Value to remove from the BST.
* Return: A pointer to the root node after deletion.
*/
bst_t *bst_remove_recursive(bst_t *Root, bst_t *TheNode, int Value)
{
if (TheNode != NULL)
{
if (TheNode->n == Value)
return (bst_delete(Root, TheNode));
if (TheNode->n > Value)
return (bst_remove_recursive(Root, TheNode->left, Value));
return (bst_remove_recursive(Root, TheNode->right, Value));
}
return (NULL);
}

/**
* bst_remove - It Removes a node from a binary search tree.
* @Root: Pointer to the root node of the BST to remove a node from.
* @Value: Value to remove in the BST.
* Return: Pointer to the new root node after deletion.
* Description: It is If the node to be deleted has two children, it
*              is replaced with its first in-order successor.
*/
bst_t *bst_remove(bst_t *Root, int Value)
{
return (bst_remove_recursive(Root, Root, Value));
}
