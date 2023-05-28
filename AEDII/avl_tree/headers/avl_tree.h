#include <stdlib.h>

// Estrutura básica de um nó de uma árvore AVL
typedef struct AVL_Node 
{
    int value;
    int height;
    struct AVL_Node *right;
    struct AVL_Node *left;
} AVL_Node;

int max(int n1, int n2)
{
    return (n1 > n2) ? n1 : n2;
}


int get_height(AVL_Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(get_height(node->left), get_height(node->right));
}


/**
 * Retorna o fator de balanceamento da árvore
*/
int get_balance(AVL_Node *node)
{
    return get_height(node->right) - get_height(node->left);
}

/**
 * Aloca memória para um novo nó da árvore e o inicializa com
 * o valor solicitado 
*/
AVL_Node* create_new_node(int value)
{
    AVL_Node *new_node = (AVL_Node*) malloc(sizeof(AVL_Node));

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 0;

    return new_node;
}

AVL_Node* rotation_left(AVL_Node *node)
{
    AVL_Node *aux, *temp;
    aux = node->right;
    temp = aux->left;
    aux->left = node;
    node->right = temp;

    return aux;
}

AVL_Node* rotation_right(AVL_Node *node)
{
    AVL_Node *aux, *temp;
    aux = node->left;
    temp = aux->right;
    aux->right = node;
    node->left = temp;

    return aux;
}

AVL_Node* insert_avl(AVL_Node *node, int value)
{
    int balance_factor = 0;
    
    if (node == NULL)
        return create_new_node(value);

    if (value > node->value)
        node->right = insert_avl(node->right, value);
    else if (value < node->value)
        node->left = insert_avl(node->left, value);

    node->height = get_height(node);
    balance_factor = get_balance(node);

    //Faz o balanceamento simples da árvore se necessário
    if (balance_factor > 1 && value > node->right->value)
        return rotation_left(node);
    if (balance_factor < -1 && value < node->left->value)
        return rotation_right(node);
    
    //Faz o balanceamento duplo da árvore se necessário
    if (balance_factor > 1 && value > node->right->value)
    {
        node->right = rotation_right(node->right);
        return rotation_left(node);
    }

    if (balance_factor < -1 && value > node->left->value)
    {
        node->left = rotation_left(node->left);
        return rotation_right(node);
    }

    return node;
}