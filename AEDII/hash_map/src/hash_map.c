#include "../headers/hash_map.h"

void insert_hash(int value, List **list, int(*hash_function)(int))
{
    int hash_result = hash_function(value);
    List *node = (List *) malloc(sizeof(List));
    node->value = value;
    node->next = NULL;

    if (list[hash_result]->value == 0)
        list[hash_result] = node;
    else
    {
        node->next = list[hash_result];
        list[hash_result] = node;
    }
}

List *search_hash(int value, List **list, int(*hash_function)(int))
{
    int hash_result = hash_function(value);
    List *aux = list[hash_result];

    while (aux != NULL)
    {
        if (aux->value == value)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void print_hash_table(List **list, int classes, int(*hash_function)(int))
{
    List *aux;
    for (int i = 0; i < classes; i++)
    {
        aux = list[i];
        while (aux != NULL)
        {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }
}