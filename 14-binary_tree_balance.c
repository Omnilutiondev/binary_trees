#include "binary_trees.h"

/**
 * binary_tree_height_b - This function measures the height of a binary tree
 * @tree: THe tree to check
 * Return: The height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t ndx = 0;
	size_t idx = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			ndx = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			idx = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((ndx > idx) ? ndx : idx);
	}
}

/**
 * binary_tree_balance - This function measures balance factor of a binary tree
 * @tree: tree to be checked
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		total = left - right;
	}
	return (total);
}

