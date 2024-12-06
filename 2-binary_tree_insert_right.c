#include "binary_trees.h"
/**
 * binary_tree_insert_right - This function adds a node in the parent
 * if it exists it move down one level and add the new node first
 * @parent: The parent of the node
 * @value: The value of the node
 * Return: NULL or the new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *noob_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	noob_node = binary_tree_node(parent, value);
	if (noob_node == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		noob_node->right = parent->right;
		parent->right->parent = noob_node;
	}
	parent->right = noob_node;
	return (noob_node);
}

