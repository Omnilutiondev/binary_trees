#include "binary_trees.h"
/**
 * tree_is_perfect - This function checks if a tree is perfect or not
 * to see if the quantity of levels in left matches the right, and also
 * check if each node has to have 2 nodes or none
 * @tree: The tree to be checked
 * Return: 0 if Success or other number that is the level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int idx = 0, ndx = 0;

	if (tree->left && tree->right)
	{
		idx = 1 + tree_is_perfect(tree->left);
		ndx = 1 + tree_is_perfect(tree->right);
		if (ndx == idx && ndx != 0 && idx != 0)
			return (ndx);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - This function checks whether it is perfect or not a tree
 * @tree: The tree to be checked
 * Return: 1 Success or 0 if Fail
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int ans = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		ans = tree_is_perfect(tree);
		if (ans != 0)
		{
			return (1);
		}
		return (0);
	}
}

