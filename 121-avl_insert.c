#include "binary_trees.h"

size_t height(const binary_tree_t *Tree);
int balance(const binary_tree_t *Tree);
avl_t *avl_insert_recursive(avl_t **Tree, avl_t *Parent,
avl_t **New, int Value);
avl_t *avl_insert(avl_t **Tree, int Value);

/**
* height - It measures the height of a binary tree.
* @Tree: Pointer to the root node of the tree to measure the height.
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t height(const binary_tree_t *Tree)
{
if (Tree != NULL)
{
size_t L = 0, R = 0;

L = Tree->left ? 1 + binary_tree_height(Tree->left) : 1;
R = Tree->right ? 1 + binary_tree_height(Tree->right) : 1;
return ((L > R) ? L : R);
}
return (0);
}

/**
* balance - It measures the balance factor of a binary tree.
* @Tree: Pointer to the root node of the tree to measure the balance factor.
* Return: If tree is NULL, return 0, else return balance factor.
*/
int balance(const binary_tree_t *Tree)
{
return (Tree != NULL ? height(Tree->left) - height(Tree->right) : 0);
}

/**
* avl_insert_recursive - It inserts a value into an AVL tree recursively.
* @Tree: Double pointer to the root node of the AVL tree to insert into.
* @Parent: Parent node of the current working node.
* @New: Double pointer to store the new node.
* @Value: Value to insert into the AVL tree.
* Return: A pointer to the new root after insertion, or NULL on failure.
*/
avl_t *avl_insert_recursive(avl_t **Tree, avl_t *Parent,
avl_t **New, int Value)
{
int B_factor;

if (*Tree == NULL)
return (*New = binary_tree_node(Parent, Value));

if ((*Tree)->n > Value)
{
(*Tree)->left = avl_insert_recursive(&(*Tree)->left, *Tree, New, Value);
if ((*Tree)->left == NULL)
return (NULL);
}
else if ((*Tree)->n < Value)
{
(*Tree)->right = avl_insert_recursive(&(*Tree)->right, *Tree, New, Value);
if ((*Tree)->right == NULL)
return (NULL);
}
else
return (*Tree);

B_factor = balance(*Tree);
if (B_factor > 1 && (*Tree)->left->n > Value)
*Tree = binary_tree_rotate_right(*Tree);
else if (B_factor < -1 && (*Tree)->right->n < Value)
*Tree = binary_tree_rotate_left(*Tree);
else if (B_factor > 1 && (*Tree)->left->n < Value)
{
(*Tree)->left = binary_tree_rotate_left((*Tree)->left);
*Tree = binary_tree_rotate_right(*Tree);
}
else if (B_factor < -1 && (*Tree)->right->n > Value)
{
(*Tree)->right = binary_tree_rotate_right((*Tree)->right);
*Tree = binary_tree_rotate_left(*Tree);
}

return (*Tree);
}

/**
* avl_insert - It inserts a value into an AVL tree.
* @Tree: Double pointer to the root node of the AVL tree to insert into.
* @Value: Value to insert into the AVL tree.
* Return: A pointer to the inserted node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **Tree, int Value)
{
avl_t *New = NULL;

if (Tree == NULL)
return (NULL);
if (*Tree == NULL)
{
*Tree = binary_tree_node(NULL, Value);
return (*Tree);
}
avl_insert_recursive(Tree, *Tree, &New, Value);
return (New);
}
