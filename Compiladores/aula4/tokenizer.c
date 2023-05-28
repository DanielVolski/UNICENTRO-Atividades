#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

TokenTable *init_tt(TokenTable *tt)
{
    tt = (TokenTable *) malloc(sizeof(TokenTable));
    tt->numbers = NULL;
    tt->operators = NULL;
    tt->parenthesis = NULL;
    return tt;
}

LinkedListNode *add_token(LinkedListNode *list, char *element)
{
    LinkedListNode *new_element = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    new_element->data = element;
    new_element->next = list;
    list = new_element;
    return list;
}

TokenTable *tokenizer(char *expr)
{
    char *aux = expr, *token = (char *) calloc(1, sizeof(char));
    int actual_state = 0, error_flag = 0;
    TokenTable *token_table = init_tt(token_table); 

    while (*aux != '\0')
    {
        switch (actual_state)
        {
        case 0:
            while (*aux >= '0' && *aux <= '9')
            {
                strncat(token, aux, 1);
                aux = aux + sizeof(char);
            }
            if (*aux == '.')
            {
                strncat(token, aux, 1);
                actual_state = 1;
                break;
            }
            else if (*aux == '+' || *aux == '-' || *aux == '*' || *aux == '/')
                actual_state = 0;

            token_table->operators = add_token(token_table->operators, aux);
            token_table->numbers = add_token(token_table->numbers, token);
            token = (char *) calloc(1, sizeof(char));

            break;
        case 1:
            while (*aux >= '0' && *aux <= '9')
            {
                strncat(token, aux, 1);
                aux = aux + sizeof(char);
            }

            if (*aux == '+' || *aux == '-' || *aux == '*' || *aux == '/')
                actual_state = 0;

            token_table->operators = add_token(token_table->operators, aux);
            token_table->numbers = add_token(token_table->numbers, token);
            token = (char *) calloc(1, sizeof(char));

            break;
        }
        aux = aux + sizeof(char);
    }
    return token_table;
}