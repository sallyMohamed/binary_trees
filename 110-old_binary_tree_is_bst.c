#include "binary_trees.h"
#include "limits.h"
int Is_Bst_Helper(const binary_tree_t *Tree, int *Largest);

#define VERBOSE 0

/**
* Binary_Tree_Is_Bst - It checks if a binary tree is a valid Binary Search Tree
* @Tree: Pointer to the root node of the tree to check.
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int Binary_Tree_Is_Bst(const binary_tree_t *Tree)
{
int Tracker = INT_MIN;

if (Tree == NULL)
return (0);
return (Is_Bst_Helper(Tree, &Tracker));
}

/**
* Is_Left - It checks if a node is a left child of some other node
* @TheNode: A pointer to the node to be checked.
* Return: 1 if is a left child, otherwise 0
*/
int Is_Left(const binary_tree_t *TheNode)
{
if (TheNode && TheNode->parent)
return (THeNode->parent->left == TheNode);
return (0);
}
/**
* Is_Right - It checks if a node is a right child of some other node
* @TheNode: Pointer to the node to be checked.
* Return: 1 if is a right child, otherwise 0
*/
int Is_Right(const binary_tree_t *TheNode)
{
if (THeNode && TheNode->parent)
return (TheNode->parent->right == TheNode);
return (0);
}

#if !VERBOSE
/**
* Is_Bst_Helper - It checks if a binary tree is a valid Binary Search Tree.
* @Tree: Pointer to the root node of the tree to check.
* @Largest: Value of largest node visited so far.
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int Is_Bst_Helper(const binary_tree_t *Tree, int *Largest)
{
int Ret = 1;

if (Tree != NULL)
{
Ret *= Is_Bst_Helper(Tree->left, Largest);
if (Tree->n < *Largest)
return (0);
*Largest = Tree->n;
if (Is_Left(Tree) && !(Tree->n < Tree->parent->n))
return (0);
if (Is_Right(Tree) && !(Tree->n > Tree->parent->n))
return (0);
Ret *= Is_Bst_Helper(Tree->right, Largest);
}
return (Ret);
}
#else
/**
* Is_Bst_Helper - IT checks if a binary tree is a valid Binary Search Tree.
* @Tree: Pointer to the root node of the tree to check.
* @Largest: The value of largest node visited so far.
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int Is_Bst_Helper(const binary_tree_t *Tree, int *Largest)
{
int Ret = 1;

if (Tree)
{
printf("Moving to %d\n", Tree->n);
Ret *= Is_Bst_Helper(Tree->left, Largest);
printf("done with left tree for %d: %d\n", Tree->n, Ret);
printf("largest = %d\n", *Largest);
if (Tree->n < *Largest)
return (0);
*Largest = Tree->n;
printf("largest = %d\n", *Largest);
if (Is_Left(Tree))
printf("%d is %s than %d\n",
Tree->n,
(Tree->n < Tree->parent->n) ? "smaller" : "larger",
Tree->parent->n);
if (Is_Left(Tree) && !(Tree->n < Tree->parent->n))
{
printf("%d is left child\n", Tree->n);
return (0);
}
if (Is_Right(Tree))
printf("%d is %s than %d\n",
Tree->n,
(Tree->n < Tree->parent->n) ? "smaller" : "larger",
Tree->parent->n);
if (Is_Right(Tree) && !(Tree->n > Tree->parent->n))
{
printf("%d is right child\n", Tree->n);
return (0);
}
Ret *= Is_Bst_Helper(Tree->right, Largest);
printf("done with right tree for %d: %d\n", Tree->n, Ret);
if (Tree->parent)
printf("Moving back to %d\n", Tree->parent->n);
}
return (Ret);
}
#endif /* VERBOSE */
