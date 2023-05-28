#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE
typedef struct LinkedListNode
{
    char *data;
    struct LinkedListNode *next;
} LinkedListNode;
#endif

#ifndef TOKEN_TABLE
#define TOKEN_TABLE
typedef struct TokenTable
{
    LinkedListNode *numbers;
    LinkedListNode *operators;
    LinkedListNode *parenthesis;
} TokenTable;
#endif

#ifndef LINKED_LIST_FUNCTIONS
#define LINKED_LIST_FUNCTIONS
LinkedListNode *add_token(LinkedListNode *list, char *element);
TokenTable *tokenizer(char *expr);
#endif

#ifndef TOKEN_TABLE_FUNCTIONS
#define TOKEN_TABLE_FUNCTIONS
TokenTable *init_tt(TokenTable *tt);
#endif