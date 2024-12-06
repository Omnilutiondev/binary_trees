#include "binary_trees.h"
/**
 * binary_tree_preorder - This function prints using pre-order traversal
 * @tree: The tree to scan
 * @func: The parameters to use
 * Return: Nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}

