#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	/* Create a new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* If the parent already has a left child, adjust the pointers */
	if (parent->left != NULL)
	{
		new_node->left = parent->left;   /* New node takes the parent's left child */
		parent->left->parent = new_node; /* Set the leftchild's parent*/
	}

	/* Set the parent's left child to the new node */
	parent->left = new_node;

	return (new_node);
}
