#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a binary node
 * @parent: the node parent
 * @value: The value of the node
 * Return: the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *noob_node;

	noob_node = malloc(sizeof(binary_tree_t));
	if (noob_node == NULL)
	{
		return (NULL);
	}
	noob_node->n = value;
	noob_node->parent = parent;
	noob_node->left = NULL;
	noob_node->right = NULL;
	return (noob_node);
}
