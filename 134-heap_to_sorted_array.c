#include "binary_trees.h"

/**
* tree_size - IT measures the sum of heights of a binary tree
* @Tree: Pointer to the root node of the tree to measure the height
* Return: Height or 0 if tree is NULL
*/
size_t tree_size(const binary_tree_t *Tree)
{
size_t height_L = 0;
size_t height_R = 0;

if (!Tree)
return (0);

if (Tree->left)
height_L = 1 + tree_size(Tree->left);

if (Tree->right)
height_R = 1 + tree_size(Tree->right);

return (height_L + height_R);
}

/**
* heap_to_sorted_array - It converts a Binary Max Heap
* to a sorted array of integer
* @Heap: Pointer to the root node of the heap to convert
* @Size: Address to store the size of the array
* Return: pointer to array sorted in descending order
**/
int *heap_to_sorted_array(heap_t *Heap, size_t *Size)
{
int e, *o = NULL;

if (!Heap || !Size)
return (NULL);

*Size = tree_size(Heap) + 1;

o = malloc(sizeof(int) * (*Size));

if (!o)
return (NULL);

for (e = 0; Heap; e++)
o[e] = heap_extract(&Heap);

return (o);
}
