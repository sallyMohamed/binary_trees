#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Data structures used in this project */

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;


/* helper function */

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */

void binary_tree_print(const binary_tree_t *);

/* Task function prototypes */

levelorder_queue_t *Create_TheNode(binary_tree_t *TheNode);
void Free_TheQueue(levelorder_queue_t *Head);
void Push(binary_tree_t *TheNode, levelorder_queue_t *Head,
levelorder_queue_t **Tail);
void Pop(levelorder_queue_t **Head);
int Binary_Tree_Is_Complete(const binary_tree_t *Tree);
binary_tree_t *Binary_Tree_Rotate_Left(binary_tree_t *Tree);
binary_tree_t *Binary_Tree_Rotate_Right(binary_tree_t *Tree);
int Binary_Tree_Is_Bst(const binary_tree_t *Tree);
int Binary_Tree_Is_Bst(const binary_tree_t *Tree);
int Is_Left(const binary_tree_t *TheNode);
int Is_Right(const binary_tree_t *TheNode);
bst_t *Bst_Insert(bst_t **Tree, int Value);
bst_t *Array_To_Bst(int *Array, size_t Size);
bst_t *Bst_Search(const bst_t *Tree, int Value);
bst_t *Inorder_Successor(bst_t *Root);
bst_t *Bst_Delete(bst_t *Root, bst_t *TheNode);
bst_t *Bst_Remove_Recursive(bst_t *Root, bst_t *TheNode, int Value);
bst_t *Bst_Remove(bst_t *Root, int Value);
size_t Height(const binary_tree_t *Tree);
int Is_Avl_Helper(const binary_tree_t *Tree, int Lo, int Hi);
int Binary_Tree_Is_Avl(const binary_tree_t *Tree);
avl_t *Array_To_Avl(int *Array, size_t Size);
/*sally*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
#endif /* BINARY_TREES_H */
