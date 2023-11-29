#include "binary_trees.h"

/**
* array_to_heap - It builds a Max Binary Heap tree from an array
* @Array: Pointer to the first element of the array to be converted
* @Size: Number of element in the array
* Return: Pointer to the root node of the created Binary Heap
*         NULL on failure
*/
heap_t *array_to_heap(int *Array, size_t Size)
{
unsigned int e;
heap_t *Root = NULL;

for (e = 0; e < Size; e++)
heap_insert(&Root, Array[e]);
return (Root);
}
