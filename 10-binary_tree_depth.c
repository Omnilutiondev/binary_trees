#include "binary_trees.h"
/**
 * binary_tree_depth - This function checks the depth of a node
 * @tree: The node to check
 * Return: 0 for root or value of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

