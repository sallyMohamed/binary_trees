#include "binary_trees.h"

/**
* Array_To_Avl - It builds an AVL tree from an array.
* @Array: Pointer to the first element of the array to be converted.
* @Size: Number of elements in @array.
* Return: Pointer to the root node of the created AVL, or NULL upon failure.
*/
avl_t *Array_To_Avl(int *Array, size_t Size)
{
avl_t *Tree = NULL;
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
if (Avl_Insert(&Tree, Array[e]) == NULL)
return (NULL);
}
}
return (Tree);
}
