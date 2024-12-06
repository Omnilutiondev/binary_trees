#include "binary_trees.h"
/**
 * check_sub_tree_Left - This function checks if all nodes are smaller than
 * the root
 * @node: The node in the tree to be verified
 * @max: The value to compare
 * Return: 1 if equal or less and 0 greater
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int lf = 0, rt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		lf = check_sub_tree_Left(node->left, max);
		rt = check_sub_tree_Left(node->right, max);
		if (lf == rt && lf == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - This function checks if all the nodes are bigger than the
 * root
 * @node: The node in the tree to be verify
 * @min: The value to be compared
 * Return: 1 if equal or bigger and 0 greater
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int lf = 0, rt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		lf = check_sub_tree_Right(node->left, min);
		rt = check_sub_tree_Right(node->right, min);
		if (lf == rt && lf == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - This function checks if a tree is a bst or not
 * by first verifying that the left node be smaller than the root
 * then verify if the right node is bigger than th root.
 * then verify if the left subtree has nodes smaller than root
 * and finally the right subtree has bigger nodes than root
 * @tree: The node that point to the tree to check
 * Return: 1 on Success or 0 if Fail
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int chk = 0, lf = 2, rt = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		chk = check_sub_tree_Left(tree->left, tree->n);
		if (chk == 0)
			return (0);
		lf = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		chk = check_sub_tree_Right(tree->right, tree->n);
		if (chk == 0)
			return (0);
		rt = binary_tree_is_bst(tree->right);
	}
	if (lf != 2 || rt != 2)
	{
		if (lf == 0 || rt == 0)
			return (0);
	}
	return (1);
}

