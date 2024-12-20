#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree in in-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: In-order traversal visits the left subtree first,
 *              then the current node, and finally the right subtree.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Recur on the left subtree */
	binary_tree_inorder(tree->left, func);

	/* Visit the current node */
	func(tree->n);

	/* Recur on the right subtree */
	binary_tree_inorder(tree->right, func);
}
