#include <stdio.h>
#include "../headers/binary_tree.h"
#include "../headers/linked_list.h"

// Função responsável pela incialização da árvore
BinaryTreeNode* init_binary_tree(BinaryTreeNode *node)
{
    node = NULL;
    return node;
}

// Função para a inserção de novos nós na árvore binária
BinaryTreeNode* insert_in_binary_tree(BinaryTreeNode *node, int value)
{
    if (node == NULL)
    {
        BinaryTreeNode *new_node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        node = new_node;
    }
    else
    {
        if (node->value < value)
            node->right = insert_in_binary_tree(node->right, value);
        else
            node->left = insert_in_binary_tree(node->left, value);
    }
    return node;
}

// Faz a busca pelo valor solicitado a partir do nó raiz da árvore
BinaryTreeNode* search_in_binary_tree(BinaryTreeNode *root, int value)
{
    if (root == NULL)
        return NULL;
    else
    {
        BinaryTreeNode *aux_node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
        aux_node = root;
        while (aux_node->value != value)
        {
            if (aux_node->value < value && aux_node->right != NULL)
                aux_node = aux_node->right;
            else if (aux_node->value > value && aux_node->left != NULL)
                aux_node = aux_node->left;
            else
                break;
        }
        // Garante que o valor encontrado está na árvore
        if (aux_node->value == value) 
            return aux_node;
        else 
            return NULL;
    }
}

void bfs(BinaryTreeNode *root)
{
    ListNode *list = NULL;
    list = insert_last_ll(list, root);
    while (list != NULL)
    {   
        printf("%d ", list->tree_node->value);
        if (list->tree_node != NULL)
        {
            if (list->tree_node->left != NULL)
                list = insert_last_ll(list, list->tree_node->left);
            if (list->tree_node->right != NULL)
                list = insert_last_ll(list, list->tree_node->right);
        }
        list = list->next;
    }
}