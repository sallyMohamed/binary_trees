#include "binary_trees.h"

levelorder_queue_t *Create_TheNode(binary_tree_t *TheNode);
void Free_TheQueue(levelorder_queue_t *Head);
void Push(binary_tree_t *TheNode, levelorder_queue_t *Head,
levelorder_queue_t **Tail);
void Pop(levelorder_queue_t **Head);
int Binary_Tree_Is_Complete(const binary_tree_t *Tree);

/**
* Create_TheNode - Function that creates a new levelorder_queue_t node.
* @TheNode: Binary tree node for the new node to contain.
* Return: If an error occurs, NULL.
*         Otherwise, a pointer to the new node.
*/
levelorder_queue_t *Create_TheNode(binary_tree_t *TheNode)
{
levelorder_queue_t *New;

New = malloc(sizeof(levelorder_queue_t));
if (new == NULL)
return (NULL);

New->TheNode = TheNode;
New->next = NULL;

return (New);
}

/**
* Free_TheQueue - Function that frees a levelorder_queue_t queue.
* @Head: Pointer to the head of the queue.
*/
void Free_TheQueue(levelorder_queue_t *Head)
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
* Push - Function that pushes a node to the back of a levelorder_queue_t queue.
* @TheNode: Binary tree node to print and push.
* @Head: A double pointer to the head of the queue.
* @Tail: A double pointer to the tail of the queue.
* Description: Upon malloc failure, exits with a status code of 1.
*/
void Push(binary_tree_t *TheNode, levelorder_queue_t *Head,
levelorder_queue_t **Tail)
{
levelorder_queue_t *New;

New = Create_TheNode(TheNode);
if (New == NULL)
{
Free_TheQueue(Head);
exit(1);
}
(*Tail)->next = New;
*Tail = New;
}

/**
* Pop - Function that pops the head of a levelorder_queue_t queue.
* @Head: Double pointer to the head of the queue.
*/
void Pop(levelorder_queue_t **Head)
{
levelorder_queue_t *Temp;

Temp = (*Head)->next;
free(*Head);
*Head = Temp;
}

/**
* Binary_Tree_Is_Complete - Function that checks if a binary tree is complete.
* @Tree: Pointer to the root node of the tree to traverse.
* Return: If the tree is NULL or not complete, 0.
*         Otherwise, 1.
* Description: It's upon malloc failure, exits with a status code of 1.
*/
int Binary_Tree_Is_Complete(const binary_tree_t *Tree)
{
levelorder_queue_t *Head, *Tail;
unsigned char Flag = 0;

if (Tree == NULL)
return (0);

Head = Tail = Create_TheNode((binary_tree_t *)Tree);
if (Head == NULL)
exit(1);

while (Head != NULL)
{
if (Head->TheNode->left != NULL)
{
if (Flag == 1)
{
Free_TheQueue(Head);
return (0);
}
Push(Head->TheNode->left, Head, &Tail);
}
else
Flag = 1;
if (Head->TheNode->right != NULL)
{
if (Flag == 1)
{
Free_TheQueue(Head);
return (0);
}
Push(Head->TheNode->right, Head, &Tail);
}
else
Flag = 1;
Pop(&Head);
}
return (1);
}
