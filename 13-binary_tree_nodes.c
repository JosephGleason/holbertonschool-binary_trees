#include "binary_trees.h"  /* For binary_tree_t type */

/**
 * binary_tree_nodes - Counts the number of nodes with at least one child
 * @tree: A pointer to the root node of the tree to count
 *
 * Return: The number of nodes with at least one child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL || tree->right != NULL)
	{
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	}

	return (0);
}
