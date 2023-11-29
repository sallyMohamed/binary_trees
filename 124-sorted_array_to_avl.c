#include "binary_trees.h"

/**
 * create_tree - It creates an AVL tree with recursion
 * @TheNode: Pointer node
 * @Array: Input array of integers
 * @Size: Size of array
 * @Mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **TheNode, int *Array, size_t Size, int Mode)
{
size_t Middle;
if (Size == 0)
return;
Middle = (Size / 2);
Middle = (Size % 2 == 0) ? Middle - 1 : Middle;
if (Mode == 1)
{
(*TheNode)->left = binary_tree_node(*TheNode, Array[Middle]);
create_tree(&((*TheNode)->left), Array, Middle, 1);
create_tree(&((*TheNode)->left), Array + Middle + 1, (Size - 1 - Middle), 2);
}
else
{
(*TheNode)->right = binary_tree_node(*TheNode, Array[Middle]);
create_tree(&((*TheNode)->right), Array, Middle, 1);
create_tree(&((*TheNode)->right), Array + Middle + 1, (Size - 1 - Middle), 2);
}
}

/**
 * sorted_array_to_avl - It creates root node and calls to create_tree
 * @Array: Input array of integers
 * @Size: Size of array
 * Return: Pointer to the root
 */
avl_t *sorted_array_to_avl(int *Array, size_t Size)
{
avl_t *Root;
size_t Middle;
Root = NULL;
if (Size == 0)
return (NULL);
Middle = (Size / 2);
Middle = (Size % 2 == 0) ? Middle - 1 : Middle;
Root = binary_tree_node(Root, Array[Middle]);
create_tree(&Root, Array, Middle, 1);
create_tree(&Root, Array + Middle + 1, (Size - 1 - Middle), 2);
return (Root);
}
