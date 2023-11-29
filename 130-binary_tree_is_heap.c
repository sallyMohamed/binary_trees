#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
* check_max - It goes through a binary tree cheking ropt as max value
* @Tree: Pointer to the root
* Return: 1 if all nodes are max, 0 in other cases
**/
int check_max(const binary_tree_t *Tree)
{
int Temp1 = 1, Temp2 = 1;

if (!Tree)
return (0);
if (!Tree->left && !Tree->right)
return (1);
if (Tree->left)
{
if (Tree->n <= Tree->left->n)
return (0);
Temp1 = check_max(Tree->left);
}
if (Tree->right)
{
if (Tree->n <= Tree->right->n)
return (0);
Temp2 = check_max(Tree->right);
}
return (Temp1 && Temp2);
}
/**
* binary_tree_is_heap - It checks if a binary tree is heap
* @Tree: Pointer to the node
* Return: 1 in case BTS /  0 otherwise
**/
int binary_tree_is_heap(const binary_tree_t *Tree)
{
int Temp;

if (!Tree)
return (0);

Temp = binary_tree_is_complete(Tree);
if (!Temp)
return (0);
return (check_max(Tree));
}
