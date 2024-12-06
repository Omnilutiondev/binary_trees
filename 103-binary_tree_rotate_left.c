#include "binary_trees.h"

/**
 * binary_tree_rotate_left - This function rotates left on the binary tree.
 * @tree: The root of the tree
 * Return: The new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *roll;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	roll = tree->right;
	tree->right = roll->left;
	if (roll->left != NULL)
	{
		roll->left->parent = tree;
	}
	roll->left = tree;
	roll->parent = tree->parent;
	tree->parent = roll;
	return (roll);
}

