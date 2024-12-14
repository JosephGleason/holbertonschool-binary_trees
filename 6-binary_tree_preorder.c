#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree in pre-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: Pre-order traversal visits the current node first,
 *              then the left subtree, and finally the right subtree.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Visit the current node */
	func(tree->n);

	/* Recur on the left subtree */
	binary_tree_preorder(tree->left, func);

	/* Recur on the right subtree */
	binary_tree_preorder(tree->right, func);
}

