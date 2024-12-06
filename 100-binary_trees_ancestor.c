#include "binary_trees.h"

/**
 * binary_trees_ancestor - This function checks for an ancestor
 * @first: The first node
 * @second: The second node
 * Return: the node containing ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *pan, *qan;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	pan = first->parent;
	qan = second->parent;
	if (pan == NULL || first == qan || (!pan->parent && qan))
	{
		return (binary_trees_ancestor(first, qan));
	}
	else if (qan == NULL || pan == second || (!qan->parent && pan))
	{
		return (binary_trees_ancestor(pan, second));
	}
	return (binary_trees_ancestor(pan, qan));
}

