#include "binary_trees.h"
/**
 * binary_tree_height - This function measures the height of a binary tree
 * @tree: The tree to check
 * Return: the total height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t idx = 0;
	size_t ndx = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			idx = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			ndx = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((idx > ndx) ? idx : ndx);
	}
}
/**
 * binary_tree_depth - This function checks the depth of a specified node
 * @tree: the node to be checked
 * Return: 0 if it is the root or the depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - A function to create a linked list from depth level and node
 * @head: This is the pointer to head of linked list
 * @tree: The node to store
 * @level: The depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *nex, *brk;

	nex = malloc(sizeof(link_t));
	if (nex == NULL)
	{
		return;
	}
	nex->n = level;
	nex->node = tree;
	if (*head == NULL)
	{
		nex->next = NULL;
		*head = nex;
	}
	else
	{
		brk = *head;
		while (brk->next != NULL)
		{
			brk = brk->next;
		}
		nex->next = NULL;
		brk->next = nex;
	}
}
/**
 * recursion - This function scans the tree and stores each node
 * in linked_node function
 * @head: The pointer to head of linked list
 * @tree: The node to be checked
 * Return: Nothing by default it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - This function prints the nodes in a lever-order
 * @tree: The root node
 * @func: The function to be used
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *brk;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			brk = head;
			while (brk != NULL)
			{
				if (count == brk->n)
				{
					func(brk->node->n);
				}
				brk = brk->next;
			}
			count++;
		}
		while (head != NULL)
		{
			brk = head;
			head = head->next;
			free(brk);
		}
	}
}

