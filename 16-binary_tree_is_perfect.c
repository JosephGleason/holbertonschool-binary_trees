#include "binary_trees.h"

/* Helper function prototype */
int baseline_check(const binary_tree_t *tree, int current_depth, int baseline);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 if it is not or tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *current = (binary_tree_t *)tree;
	int baseline = 0;

	if (tree == NULL)
		return (0);

	/* Calculate the baseline depth by traversing down the leftmost branch.*/
	while (current->left != NULL)
	{
		baseline++;
		current = current->left;
	}

	/* Start the recursive checking from the root with current_depth = 0 */
	return (baseline_check(tree, 0, baseline));
}

/**
 * baseline_check - Recursively checks that every leaf is at the same depth.
 * @tree: Pointer to the current node.
 * @current_depth: The current depth during traversal.
 * @baseline: The baseline depth computed from the leftmost branch.
 *
 * Return: 1 if the subtree rooted at tree is perfect, 0 otherwise.
 */
int baseline_check(const binary_tree_t *tree, int current_depth, int baseline)
{
	/* Base case: if we're at a leaf, check that its depth equals the baseline */
	if (tree->left == NULL && tree->right == NULL)
		return (current_depth == baseline);

	/* If one child is missing, the tree cannot be perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Recursively check both subtrees, incrementing the current depth by one */
	return (baseline_check(tree->left, current_depth + 1, baseline) &&
			baseline_check(tree->right, current_depth + 1, baseline));
}
