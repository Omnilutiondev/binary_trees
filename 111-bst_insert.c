#include "binary_trees.h"
/**
 * bst_insert - This function inserts nodes in order to create a BST tree
 * @tree: The tree to create with type BST
 * @value: The value of node to insert
 * Return: The BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *fnc, *tnc;
	binary_tree_t *idc;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		idc = binary_tree_node((binary_tree_t *)(*tree), value);
		fnc = (bst_t *)idc;
		*tree = fnc;
	}
	else
	{
		tnc = *tree;
		if (value < tnc->n)
		{
			if (tnc->left)
				fnc = bst_insert(&tnc->left, value);
			else
			{
				idc = binary_tree_node((binary_tree_t *)tnc, value);
				fnc = tnc->left = (bst_t *)idc;
			}
		}
		else if (value > tnc->n)
		{
			if (tnc->right)
				fnc = bst_insert(&tnc->right, value);
			else
			{
				idc = binary_tree_node((binary_tree_t *)tnc, value);
				fnc = tnc->right = idc;
			}
		}
		else
			return (NULL);
	}
	return (fnc);
}

