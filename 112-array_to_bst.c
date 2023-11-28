#include "binary_trees.h"

/**
* Array_To_Bst - It builds a binary search tree from an array.
* @Array: Pointer to the first element of the array to be converted.
* @Size: Number of elements in @array.
* Return: A pointer to the root node of the created BST, or NULL upon failure.
*/
bst_t *Array_To_Bst(int *Array, size_t Size)
{
bst_t *Tree = NULL;
size_t e, k;

if (Array == NULL)
return (NULL);

for (e = 0; e < Size; e++)
{
for (k = 0; k < e; k++)
{
if (Array[k] == Array[e])
break;
}
if (k == e)
{
if (Bst_Insert(&Tree, Array[e]) == NULL)
return (NULL);
}
}

return (Tree);
}
