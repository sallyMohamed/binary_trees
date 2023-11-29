#include "binary_trees.h"
#include <stdlib.h>

/**
* tree_height - It measures the height of a binary tree
* @Tree: Pointer to the root node of the tree to measure the height
* Return: Height or 0 if tree is NULL
*/
size_t tree_height(const heap_t *Tree)
{
size_t height_L = 0;
size_t height_R = 0;

if (!Tree)
return (0);

if (Tree->left)
height_L = 1 + tree_height(Tree->left);

if (Tree->right)
height_R = 1 + tree_height(Tree->right);

if (height_L > height_R)
return (height_L);
return (height_R);
}
/**
* tree_size_h - It measures the sum of heights of a binary tree
* @Tree: Pointer to the root node of the tree to measure the height
* Return: Height or 0 if tree is NULL
*/
size_t tree_size_h(const binary_tree_t *Tree)
{
size_t height_L = 0;
size_t height_R = 0;

if (!Tree)
return (0);

if (Tree->left)
height_L = 1 + tree_size_h(Tree->left);

if (Tree->right)
height_R = 1 + tree_size_h(Tree->right);

return (height_L + height_R);
}

/**
* _preorder - It goes through a binary tree using pre-order traversal
* @Tree: Pointer to the root node of the tree to traverse
* @node: will be last note in traverse
* @Height: height of tree
* Return: No Return
*/
void _preorder(heap_t *Tree, heap_t **node, size_t Height)
{
if (!Tree)
return;

if (!Height)
*node = Tree;
Height--;

_preorder(Tree->left, node, Height);
_preorder(Tree->right, node, Height);
}

/**
* heapify - It heapifies max binary heap
* @Root: Pointer to binary heap
*/
void heapify(heap_t *Root)
{
int Value;
heap_t *Temp1, *Temp2;

if (!Root)
return;

Temp1 = Root;

while (1)
{
if (!Temp1->left)
break;
if (!Temp1->right)
Temp2 = Temp1->left;
else
{
if (Temp1->left->n > Temp1->right->n)
Temp2 = Temp1->left;
else
Temp2 = Temp1->right;
}
if (Temp1->n > Temp2->n)
break;
Value = Temp1->n;
Temp1->n = Temp2->n;
Temp2->n = Value;
Temp1 = Temp2;
}
}

/**
* heap_extract - IT extracts the root node from a Max Binary Heap
* @Root: Pointer to the heap root
* Return: value of extracted node
**/
int heap_extract(heap_t **Root)
{
int Value;
heap_t *heap_R, *node;

if (!Root || !*Root)
return (0);
heap_R = *Root;
Value = heap_R->n;
if (!heap_R->left && !heap_R->right)
{
*Root = NULL;
free(heap_R);
return (Value);
}

_preorder(heap_R, &node, tree_height(heap_R));

heap_R->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
heapify(heap_R);
*Root = heap_R;
return (Value);
}
