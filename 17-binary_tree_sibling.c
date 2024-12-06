#include "binary_trees.h"

/**
 * binary_tree_sibling - This function finds if a node is a duplicate
 * @node: The node to checked
 * Return: The dubplicate node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}

