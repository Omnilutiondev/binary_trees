#include "binary_trees.h"

/**
 * binary_tree_rotate_right - This function rotates right in the binary tree.
 * @tree: The root node of the tree
 * Return: The new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *roll;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	roll = tree->left;
	tree->left = roll->right;
	if (roll->right != NULL)
	{
		roll->right->parent = tree;
	}
	roll->right = tree;
	roll->parent = tree->parent;
	tree->parent = roll;
	return (roll);
}

