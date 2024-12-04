#include "binary_trees.h"
/**
 * binary_tree_insert_left - This function adds a node in the left of the parent
 * if it exists it move down one level and add the new node first
 * @parent: The parent of the specified node
 * @value: The value of the node
 * Return: NULL if fails or the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left != NULL)
	{
		noob_node->left = parent->left;
		parent->left->parent = noob_node;
	}
	parent->left = noob_node;
	return (noob_node);
}

