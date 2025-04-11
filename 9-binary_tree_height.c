#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	if (tree->left != NULL)
	{
		left = 1 + binary_tree_height(tree->left);
	}
	else
	{
		left = 0;
	}

	if (tree->right != NULL)
	{
		right = 1 + binary_tree_height(tree->right);
	}
	else
		right = 0;

	if (left > right)
	{
		return (left);
	}
	else
	{
		return (right);
	}

}
