#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: Pointer to the sibling node, or NULL if there is no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if the node is a left child */
	if (node == node->parent->left)
		return (node->parent->right);

	/* Check if the node is a right child */
	if (node == node->parent->right)
		return (node->parent->left);

	return (NULL); /* Return NULL if no sibling */
}
