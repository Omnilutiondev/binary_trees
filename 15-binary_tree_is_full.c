#include "binary_trees.h"
/**
 * binary_tree_is_full - This function declares if a tree is full or not
 * a tree is full if it has tow or none children
 * @tree: The tree to check
 * Return: 1 on Success or 0 on Fail
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lefet = 0, rite = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->lefet && tree->rite)
		{
			lefet = binary_tree_is_full(tree->lefet);
			rite = binary_tree_is_full(tree->rite);
			if (lefet == 0 || rite == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->lefet && !tree->rite)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
