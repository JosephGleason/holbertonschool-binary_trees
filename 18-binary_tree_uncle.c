#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle of.
 *
 * Return: Pointer to the uncle node, or NULL if there is no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);  /* No uncle if node or parent's parent is NULL */

	/* Check if the node's parent is a left child */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);  /* Return right uncle if left child */

	/* Check if the node's parent is a right child */
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);  /* Return left uncle if right child */

	return (NULL);  /* Return NULL if no uncle */
}

