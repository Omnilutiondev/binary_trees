#include "binary_trees.h"
/**
 * binary_tree_is_leaf - This function checks if a node is a leaf, to verify if a node
 * does not have any child neither left nor right
 * @node: The node to check
 * Return: 1 Success or 0 if fail
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

