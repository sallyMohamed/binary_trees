#include "binary_trees.h"


/**
 * p_create - Create newNode.
 * @p_node: POINTER to node.
 *
 * Return: NULL Else pointer to newNode.
 */
levelorder_queue_t *p_create(binary_tree_t *p_node)
{
	levelorder_queue_t *p_new;

	p_new = malloc(sizeof(levelorder_queue_t));
	if (p_new == NULL)
		return (NULL);

	p_new->node = p_node;
	p_new->next = NULL;

	return (p_new);
}

/**
 * p_free - Free queue.
 * @p_head: Head.
 */
void p_free(levelorder_queue_t *p_head)
{
	levelorder_queue_t *t;

	while (p_head != NULL)
	{
		t = p_head->next;
		free(p_head);
		p_head = t;
	}
}

/**
 * p_push - pushe into queue.
 * @p_node: node.
 * @p_head: head.
 * @p_tail: tail.
 * @pf: Function to our node.
 *
 * Description: Mallco Error Else status 1.
 */
void p_push(binary_tree_t *p_node, levelorder_queue_t *p_head,
		levelorder_queue_t **p_tail, void (*pf)(int))
{
	levelorder_queue_t *p_new;

	pf(p_node->n);
	if (p_node->left != NULL)
	{
		p_new = p_create(p_node->left);
		if (p_new == NULL)
		{
			p_free(p_head);
			exit(1);
		}
		(*p_tail)->next = p_new;
		*p_tail = p_new;
	}
	if (p_node->right != NULL)
	{
		p_new = p_create(p_node->right);
		if (p_new == NULL)
		{
			p_free(p_head);
			exit(1);
		}
		(*p_tail)->next = p_new;
		*p_tail = p_new;
	}
}

/**
 * p_pop - Pop Queue.
 * @p_head: Head.
 */
void p_pop(levelorder_queue_t **p_head)
{
	levelorder_queue_t *t;

	t = (*p_head)->next;
	free(*p_head);
	*p_head = t;
}

/**
 * binary_tree_levelorder - Levelorder.
 * @p: Pointer.
 * @pf: Function CaLL Node.
 */
void binary_tree_levelorder(const binary_tree_t *p, void (*pf)(int))
{
	levelorder_queue_t *p_head, *p_tail;

	if (p == NULL || pf == NULL)
		return;

	p_head = p_tail = p_create((binary_tree_t *)p);
	if (p_head == NULL)
		return;

	while (p_head != NULL)
	{
		p_push(p_head->node, p_head, &p_tail, pf);
		p_pop(&p_head);
	}
}
