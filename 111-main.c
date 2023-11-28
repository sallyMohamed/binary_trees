#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
bst_t *root;
bst_t *node;

root = NULL;
node = Bst_Insert(&root, 98);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 402);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 12);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 46);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 128);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 256);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 512);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 1);
printf("Inserted: %d\n", node->n);
node = Bst_Insert(&root, 128);
printf("Node should be nil -> %p\n", (void *)node);
binary_tree_print(root);
return (0);
}
