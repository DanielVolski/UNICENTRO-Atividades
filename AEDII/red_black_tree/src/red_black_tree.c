#include <malloc.h>
#include <stdlib.h>
#include "../headers/red_black_tree.h"

RBTreeNode *new_RBTreeNode(int value)
{
	RBTreeNode *new_node = (RBTreeNode *)malloc(sizeof(RBTreeNode));
	new_node->value = value;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = NULL;
	new_node->color = RED;
	return new_node;
}

RBTreeNode *left_rotate(RBTreeNode *node, RBTreeNode *x)
{
	RBTreeNode *y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		node = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
	return node;
}

RBTreeNode *right_rotate(RBTreeNode *node, RBTreeNode *x)
{
	RBTreeNode *y = x->left;
	x->left = y->right;
	if (y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		node = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->right = x;
	x->parent = y;
	return node;
}

RBTreeNode *max_RBTree(RBTreeNode *root)
{
	RBTreeNode *aux = root;
	while (aux->right != NULL)
		aux = aux->right;
	return aux;
}

RBTreeNode *min_RBTree(RBTreeNode *root)
{
	RBTreeNode *aux = root;
	while (aux->left != NULL)
		aux = aux->left;
	return aux;
}

RBTreeNode *balance_RBTRee(RBTreeNode *node, RBTreeNode *z)
{
	RBTreeNode *y = NULL;
	while (z->parent != NULL && z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y != NULL && y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					node = left_rotate(node, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				node = right_rotate(node, z->parent->parent);
			}
		}
		else
		{
			y = z->parent->parent->left;
			if (y != NULL && y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					node = right_rotate(node, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				node = left_rotate(node, z->parent->parent);
			}
		}
	}
	node->color = BLACK;
	return node;
}

RBTreeNode *insert_RBTree(RBTreeNode *node, int value)
{
	RBTreeNode *z = new_RBTreeNode(value);
	RBTreeNode *y = NULL;
	RBTreeNode *x = node;
	while (x != NULL)
	{
		y = x;
		if (z->value < x->value)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		node = z;
	else if (z->value < y->value)
		y->left = z;
	else
		y->right = z;
	z->left = NULL;
	z->right = NULL;
	z->color = RED;
	node = balance_RBTRee(node, z);
	return node;
}

RBTreeNode *search_RBTree(RBTreeNode *node, int value)
{
	RBTreeNode *aux = node;

	while (aux != NULL && aux->value != value)
		if (aux->value > value)
			aux = aux->left;
		else
			aux = aux->right;

	return aux;
}

RBTreeNode *transplant(RBTreeNode *root, RBTreeNode *u, RBTreeNode *v)
{
	if (u->parent == NULL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v != NULL)
		v->parent = u->parent;

	return root;
}

RBTreeNode *remove_from_RBTree(RBTreeNode *node, RBTreeNode *z)
{
	RBTreeNode *x, *y;
	NODECOLOR y_original_color = z->color;

	if (z->left == NULL)
	{
		x = z->right;
		node = transplant(node, z, z->right);
	}
	else if (z->right == NULL)
	{
		x = z->left;
		node = transplant(node, z, z->left);
	}
	else
	{
		y = min_RBTree(z->right);
		y_original_color = y->color;
		x = y->right;

		if (y->parent == z)
		{
			if (x != NULL)
			{
				x->parent = y;
			}
		}
		else
		{
			node = transplant(node, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		node = transplant(node, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if (y_original_color == BLACK)
	{
		node = balance_RBTRee(node, x);
	}

	free(z);
	return node;
}

void delete_RBTree(RBTreeNode **node_ptr)
{
	RBTreeNode *node = *node_ptr;
	if (node != NULL)
	{
		delete_RBTree(&(node->left));
		delete_RBTree(&(node->right));
		free(node);
		*node_ptr = NULL;
	}
}

void print_in_order_RBTree(RBTreeNode *root)
{
	if (root != NULL)
	{
		print_in_order_RBTree(root->left);
		if (root->color == RED)
			printf("\x1b[31m%d \x1b[0m", root->value);
		else
			printf("%d ", root->value);
		print_in_order_RBTree(root->right);
	}
}

void print_pre_order_RBTree(RBTreeNode *root)
{
	if (root != NULL)
	{
		if (root->color == RED)
			printf("\x1b[31m%d \x1b[0m", root->value);
		else
			printf("%d ", root->value);
		print_pre_order_RBTree(root->left);
		print_pre_order_RBTree(root->right);
	}
}

void print_post_order_RBTree(RBTreeNode *root)
{
	if (root != NULL)
	{
		print_post_order_RBTree(root->left);
		print_post_order_RBTree(root->right);
		if (root->color == RED)
			printf("\x1b[31m%d \x1b[0m", root->value);
		else
			printf("%d ", root->value);
	}
}