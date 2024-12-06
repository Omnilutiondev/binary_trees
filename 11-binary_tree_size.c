#include "binary_trees.h"
/**
 * binary_tree_size - This function returns the size of a tree
 * @tree: The tree to check
 * Return: The size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sizze = 0, idx = 0, l = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = binary_tree_size(tree->left);
		idx = binary_tree_size(tree->right);
		sizze = idx + l + 1;
	}
	return (sizze);
}

