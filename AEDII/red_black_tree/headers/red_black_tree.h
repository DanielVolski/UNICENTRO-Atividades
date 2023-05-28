#ifndef RB_TREE_NODE_COLOR
    #define RB_TREE_NODE_COLOR
    #define NODECOLOR int
    #define BLACK 0
    #define RED 1
#endif

#ifndef RB_TREE_NODE
    #define RB_TREE_NODE
    typedef struct RBTreeNode
    {
        int value;
        struct RBTreeNode *right;
        struct RBTreeNode *left;
        struct RBTreeNode *parent;
        NODECOLOR color;
    } RBTreeNode;
#endif

#ifndef RB_TREE_FUNCTIONS
    #define RB_TREE_FUNCTIONS
    RBTreeNode* new_RBTreeNode(int value);
    RBTreeNode* left_rotate(RBTreeNode *node, RBTreeNode *x);
    RBTreeNode* right_rotate(RBTreeNode *node, RBTreeNode *x);
    RBTreeNode* max_RBTree(RBTreeNode *root);
    RBTreeNode* min_RBTree(RBTreeNode *root);
    RBTreeNode* balance_RBTRee(RBTreeNode *node, RBTreeNode *z);
    RBTreeNode* insert_RBTree(RBTreeNode *node, int value);
    RBTreeNode *search_RBTree(RBTreeNode *root, int value);
    RBTreeNode *remove_from_RBTree(RBTreeNode *node, RBTreeNode *z);
    RBTreeNode *transplant(RBTreeNode *root, RBTreeNode *u, RBTreeNode *v);
    void delete_RBTree(RBTreeNode **node);
    void print_in_order_RBTree(RBTreeNode *root);
    void print_pre_order_RBTree(RBTreeNode *root);
    void print_post_order_RBTree(RBTreeNode *root);
#endif