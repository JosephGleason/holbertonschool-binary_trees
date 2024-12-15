#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree.
 */
static size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_perfect_helper - Helper function to check if a tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * @depth: The depth of the current node.
 * @level: The depth of the leaf nodes.
 *
 * Return: 1 if the tree is perfect, 0 if it is not.
 */
static int is_perfect_helper(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	/* If it's a leaf node, check if it's at the correct level */
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);

	/* If it's not a leaf node, ensure it has both children */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recursively check both subtrees */
	return (is_perfect_helper(tree->left, depth + 1, level) &&
			is_perfect_helper(tree->right, depth + 1, level));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 if it is not or tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Calculate the height of the tree */
	size_t height = binary_tree_height(tree);

	/* Start the check for perfection from the root */
	return (is_perfect_helper(tree, 0, height - 1));
}

