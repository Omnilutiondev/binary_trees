#include "binary_trees.h"
/**
 * binary_tree_nodes - This function returns # of nodes in a tree with children
 * @tree: The tree to check
 * Return: The number of nodes with children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  ndx = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		ndx += ((tree->left || tree->right) ? 1 : 0);
		ndx += binary_tree_nodes(tree->left);
		ndx += binary_tree_nodes(tree->right);
		return (ndx);
	}
}

