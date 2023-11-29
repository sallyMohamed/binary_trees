#include "binary_trees.h"

/**
* heap_insert - It inserts a value in Max Binary Heap
* @Root: Double pointer to the root node of the Heap to insert the value
* @Value: Value to store in the node to be inserted
* Return: a pointer to the created node
*         NULL on failure
*/
heap_t *heap_insert(heap_t **Root, int Value)
{
heap_t *Tree, *New, *Flip;
int Size, Leaves, Sub, Bit, Level, Temp;

if (!Root)
return (NULL);
if (!(*Root))
return (*Root = binary_tree_node(NULL, Value));
Tree = *Root;
Size = binary_tree_size(Tree);
Leaves = Size;
for (Level = 0, Sub = 1; Leaves >= Sub; Sub *= 2, Level++)
Leaves -= Sub;

for (Bit = 1 << (Level - 1); Bit != 1; Bit >>= 1)
Tree = Leaves & Bit ? Tree->right : Tree->left;
/*
* IT Traverse tree to first empty slot based on the binary
* representation of the number of leaves.
* For Example -
* If there are 12 nodes in a complete tree, there are 5 leaves on
* the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
* right, 0 to left.
* First empty node is 101 == RLR, *root->right->left->right
*/

New = binary_tree_node(Tree, Value);
Leaves & 1 ? (Tree->right = New) : (Tree->left = New);

Flip = New;
for (; Flip->parent && (Flip->n > Flip->parent->n); Flip = Flip->parent)
{
Temp = Flip->n;
Flip->n = Flip->parent->n;
Flip->parent->n = Temp;
New = New->parent;
}

return (New);
}

/**
* binary_tree_size - IT measures the size of a binary tree
* @Tree: Tree to measure the size of
* Return: size of the tree
*         0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *Tree)
{
if (!Tree)
return (0);

return (binary_tree_size(Tree->left) + binary_tree_size(Tree->right) + 1);
}
