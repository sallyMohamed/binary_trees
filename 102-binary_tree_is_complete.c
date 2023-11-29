#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *Head);
void push(binary_tree_t *node, levelorder_queue_t *Head,
levelorder_queue_t **Tail);
void pop(levelorder_queue_t **Head);
int binary_tree_is_complete(const binary_tree_t *Tree);

/**
* create_node - Function that creates a new levelorder_queue_t node.
* @node: Binary tree node for the new node to contain.
* Return: If an error occurs, NULL.
*         Otherwise, a pointer to the new node.
*/
levelorder_queue_t *create_node(binary_tree_t *node)
{
levelorder_queue_t *New;

New = malloc(sizeof(levelorder_queue_t));
if (New == NULL)
return (NULL);

New->node = node;
New->next = NULL;

return (New);
}

/**
* free_queue - Function that frees a levelorder_queue_t queue.
* @Head: Pointer to the head of the queue.
*/
void free_queue(levelorder_queue_t *Head)
{
levelorder_queue_t *Temp;

while (Head != NULL)
{
Temp = Head->next;
free(Head);
Head = Temp;
}
}

/**
* push - Function that pushes a node to the back of a levelorder_queue_t queue.
* @node: Binary tree node to print and push.
* @Head: A double pointer to the head of the queue.
* @Tail: A double pointer to the tail of the queue.
* Description: Upon malloc failure, exits with a status code of 1.
*/
void push(binary_tree_t *node, levelorder_queue_t *Head,
levelorder_queue_t **Tail)
{
levelorder_queue_t *New;

New = create_node(node);
if (New == NULL)
{
free_queue(Head);
exit(1);
}
(*Tail)->next = New;
*Tail = New;
}

/**
* pop - Function that pops the head of a levelorder_queue_t queue.
* @Head: Double pointer to the head of the queue.
*/
void pop(levelorder_queue_t **Head)
{
levelorder_queue_t *Temp;

Temp = (*Head)->next;
free(*Head);
*Head = Temp;
}

/**
* binary_tree_is_complete - Function that checks if a binary tree is complete.
* @Tree: Pointer to the root node of the tree to traverse.
* Return: If the tree is NULL or not complete, 0.
*         Otherwise, 1.
* Description: It's upon malloc failure, exits with a status code of 1.
*/
int binary_tree_is_complete(const binary_tree_t *Tree)
{
levelorder_queue_t *Head, *Tail;
unsigned char Flag = 0;

if (Tree == NULL)
return (0);

Head = Tail = create_node((binary_tree_t *)Tree);
if (Head == NULL)
exit(1);

while (Head != NULL)
{
if (Head->node->left != NULL)
{
if (Flag == 1)
{
free_queue(Head);
return (0);
}
push(Head->node->left, Head, &Tail);
}
else
Flag = 1;
if (Head->node->right != NULL)
{
if (Flag == 1)
{
free_queue(Head);
return (0);
}
push(Head->node->right, Head, &Tail);
}
else
Flag = 1;
pop(&Head);
}
return (1);
}
