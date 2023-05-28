#include <stdio.h>
#include "../headers/avl_tree.h"

int main()
{
    AVL_Node *root = NULL;
    root = insert_avl(root, 10);

    printf("Inserindo o primeiro valor na arvore\n");
    printf("%d\n", root->value);
    printf("Fator de balanceamento: %d\n", get_balance(root));

    //O nó 5 deve ser inserido à esquerda e o nó 20 à direita
    printf("Inserindo dois novos valores na arvore\n");
    root = insert_avl(root, 5);
    root = insert_avl(root, 20);
    printf("%d\n", root->left->value);
    printf("%d\n", root->right->value);
    printf("Fator de balanceamento: %d\n", get_balance(root));

    /**
     * Deve ser feita uma rotação dupla esquerda/direita, colocando
     * o valor 16 à direita do valor 10
    */
    printf("Inserindo dois novos valores na arvore e fazendo a rotacao dupla esquerda/direita\n");
    root = insert_avl(root, 15);
    root = insert_avl(root, 16);
    printf("%d\n", root->value);
    printf("%d\n", root->left->value);
    printf("%d\n", root->right->value);
    printf("Fator de balanceamento: %d\n", get_balance(root));

    /**
     * Deve ser feita uma rotação à esquerda tornando o valor 16 o novo
     * nó raiz
    */
    printf("Inserindo o valor 17 na arvore e fazendo a rotacao dupla esquerda\n");
    root = insert_avl(root, 17);
    printf("%d\n", root->value);
    printf("%d\n", root->left->value);
    printf("%d\n", root->right->value);
    printf("Fator de balanceamento: %d\n", get_balance(root));

    return 0;
}