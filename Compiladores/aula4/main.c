#include <stdio.h>
#include "tokenizer.c"

void print_token_table(TokenTable *tt);

int main()
{
    char c[50];

    scanf("%s", &c);
    TokenTable *token_table = tokenizer(c);

    print_token_table(token_table);

    return 0;
}

void print_token_table(TokenTable *tt)
{
    TokenTable *aux = tt;

    printf("Numbers:");
    while (aux->numbers != NULL)
    {
        printf("%s ", aux->numbers->data);
        aux->numbers = aux->numbers->next;
    }
    printf("\nOperators:");
    while (aux->operators != NULL)
    {
        printf("%c ", *aux->operators->data);
        aux->operators = aux->operators->next;
    }
    printf("\nParenthesis:");
    while (aux->parenthesis != NULL)
    {
        printf("%c ", *aux->parenthesis->data);
        aux->parenthesis = aux->parenthesis->next;
    }
}