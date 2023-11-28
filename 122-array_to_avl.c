#include "binary_trees.h"

/**
* array_to_avl - It builds an AVL tree from an array.
* @Array: Pointer to the first element of the array to be converted.
* @Size: Number of elements in @array.
* Return: Pointer to the root node of the created AVL, or NULL upon failure.
*/
avl_t *array_to_avl(int *Array, size_t Size)
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
if (avl_insert(&Tree, Array[e]) == NULL)
return (NULL);
}
}
return (Tree);
}
