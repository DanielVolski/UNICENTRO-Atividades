/* Algoritmos e estrtura de dados II
 * Implementação de uma estrutura de árvore binária
 * junto de suas principais funções. Desenvolvido
 * apenas para estudos na disciplina de AEDII 
 */

#ifndef BINARY_TREE_NODE
    #define BINARY_TREE_NODE
        typedef struct BinaryTreeNode
        {
            int value;
            struct BinaryTreeNode *right;
            struct BinaryTreeNode *left;
        } BinaryTreeNode;
#endif

#ifndef BINARY_TREE_FUNCTIONS
    #define BINARY_TREE_FUNCTIONS
    BinaryTreeNode* init_binary_tree(BinaryTreeNode *node);
    BinaryTreeNode* insert_in_binary_tree(BinaryTreeNode *node, int value);
    BinaryTreeNode* search_in_binary_tree(BinaryTreeNode *root, int value);
    void bfs(BinaryTreeNode *root);
#endif