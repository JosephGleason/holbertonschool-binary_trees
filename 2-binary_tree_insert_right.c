#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	/* Create a new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* If parent alreadyhas a right child adjust the pointers */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;   /* New node takesparent's right child */
		parent->right->parent = new_node;  /* Set old rchild's parent to newnode */
	}

	/* Set the parent's right child to the new node */
	parent->right = new_node;

	return (new_node);
}

