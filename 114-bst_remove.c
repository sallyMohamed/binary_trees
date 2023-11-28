#include "binary_trees.h"

bst_t *Inorder_Successor(bst_t *Root);
bst_t *Bst_Delete(bst_t *Root, bst_t *TheNode);
bst_t *Bst_Remove_Recursive(bst_t *Root, bst_t *TheNode, int Value);
bst_t *bst_remove(bst_t *Root, int Value);

/**
* Inorder_Successor - It returns the minimum value of a binary search tree.
* @Root: Pointer to the root node of the BST to search.
* Return: The minimum value in @tree.
*/
bst_t *Inorder_Successor(bst_t *Root)
{
while (Root->left != NULL)
Root = Root->left;
return (Root);
}

/**
* Bst_Delete - It deletes a node from a binary search tree.
* @Root: Pointer to the root node of the BST.
* @TheNode: Pointer to the node to delete from the BST.
* Return: A pointer to the new root node after deletion.
*/
bst_t *Bst_Delete(bst_t *Root, bst_t *TheNode)
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
free(Theode);
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
Successor = Inorder_Successor(TheNode->right);
TheNode->n = Successor->n;

return (Bst_Delete(Root, Successor));
}

/**
* Bst_Remove_Recursive - It removes node from a binary search tree recursively
* @Root: Pointer to the root node of the BST to remove a node from.
* @TheNode: Pointer to the current node in the BST.
* @Value: Value to remove from the BST.
* Return: A pointer to the root node after deletion.
*/
bst_t *Bst_Remove_Recursive(bst_t *Root, bst_t *TheNode, int Value)
{
if (TheNode != NULL)
{
if (TheNode->n == Value)
return (bst_delete(Root, TheNode));
if (TheNode->n > Value)
return (Bst_Remove_Recursive(Root, TheNode->left, Value));
return (Bst_Remove_Recursive(Root, TheNode->right, Value));
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
return (Bst_Remove_Recursive(Root, Root, Value));
}
