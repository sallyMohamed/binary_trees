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

/* Sara */
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *Head);
void push(binary_tree_t *node, levelorder_queue_t *Head,
levelorder_queue_t **Tail);
void pop(levelorder_queue_t **Head);
int binary_tree_is_complete(const binary_tree_t *Tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *Tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *Tree);
int binary_tree_is_bst(const binary_tree_t *Tree);
int binary_tree_is_bst(const binary_tree_t *Tree);
int is_left(const binary_tree_t *TheNode);
int is_right(const binary_tree_t *TheNode);
bst_t *bst_insert(bst_t **Tree, int Value);
bst_t *array_to_bst(int *Array, size_t Size);
bst_t *bst_search(const bst_t *Tree, int Value);
bst_t *inorder_successor(bst_t *Root);
bst_t *bst_delete(bst_t *Root, bst_t *TheNode);
bst_t *bst_remove_recursive(bst_t *Root, bst_t *TheNode, int Value);
bst_t *bst_remove(bst_t *Root, int Value);
size_t height(const binary_tree_t *Tree);
int is_avl_helper(const binary_tree_t *Tree, int Lo, int Hi);
int binary_tree_is_avl(const binary_tree_t *Tree);
size_t height(const binary_tree_t *Tree);
int balance(const binary_tree_t *Tree);
avl_t *avl_insert_recursive(avl_t **Tree, avl_t *Parent,
avl_t **New, int Value);
avl_t *avl_insert(avl_t **Tree, int Value);
avl_t *array_to_avl(int *Array, size_t Size);
void bal(avl_t **Tree);
int successor(bst_t *TheNode);
int remove_type(bst_t *Root);
bst_t *bst_remove(bst_t *Root, int Value);
avl_t *avl_remove(avl_t *Root, int Value);
void create_tree(avl_t **TheNode, int *Array, size_t Size, int Mode);
avl_t *sorted_array_to_avl(int *Array, size_t Size);
int binary_tree_is_heap(const binary_tree_t *Tree);
int check_max(const binary_tree_t *Tree);
size_t binary_tree_size(const binary_tree_t *Tree);
heap_t *heap_insert(heap_t **Root, int Value);
heap_t *array_to_heap(int *Array, size_t Size);
int heap_extract(heap_t **Root);
void heapify(heap_t *Root);
void _preorder(heap_t *Tree, heap_t **node, size_t Height);
size_t tree_size_h(const binary_tree_t *Tree);
size_t tree_height(const heap_t *Tree);

/*sally*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*temporary */
void binary_tree_delete(binary_tree_t *tree);


#endif /* BINARY_TREES_H */
