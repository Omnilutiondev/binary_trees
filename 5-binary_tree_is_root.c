#include "binary_trees.h"

/**
 * binary_tree_is_root - This function checks if a node is a root
 * @node: The node to be checked
 * Return: 0 if fail or 1 if success
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}

