#include "binary_trees.h"
/**
 * new_node - This function creates a new node in a linked_list
 * @node: The type pointer of node to be created
 * Return: the new node
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *noob;

	noob =  malloc(sizeof(link_t));
	if (noob == NULL)
	{
		return (NULL);
	}
	noob->node = node;
	noob->next = NULL;

	return (noob);
}
/**
 * free_q - This function frees the nodes in the linked list
 * @head: The head node of the list
 */
void free_q(link_t *head)
{
	link_t *tmp_node;

	while (head)
	{
		tmp_node = head->next;
		free(head);
		head = tmp_node;
	}
}
/**
 * _push - This function pushes a node into the stack
 * @node: The type pointer of node of the tree
 * @head: The head node of the stack
 * @tail: The tail node of the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *noob;

	noob = noob_node(node);
	if (noob == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = noob;
	*tail = noob;
}
/**
 * _pop - Function that pops a node into the stack
 * @head: Type head node of in the stack
 */
void _pop(link_t **head)
{
	link_t *tmp_node;

	tmp_node = (*head)->next;
	free(*head);
	*head = tmp_node;
}
/**
 * binary_tree_is_complete - This function checks if a binary tree is complete
 * @tree: The type pointer of node of the tree
 * Return: 1 on Success or 0 if Fail
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}

