#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Size of the current tree is the size of the left subtree
	   plus the size of the right subtree, plus 1 for the current node */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

