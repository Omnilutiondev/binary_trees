#include "binary_trees.h"
/**
 * binary_tree_leaves - This function returns the number of leaves in a tree
 * @tree: The tree to check
 * Return: Total number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lif = 0, l = 0, idx = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = binary_tree_leaves(tree->left);
		idx = binary_tree_leaves(tree->right);
		lif = l + idx;
		return ((!l && !idx) ? lif + 1 : lif + 0);
	}
}

