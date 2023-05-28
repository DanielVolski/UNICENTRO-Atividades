#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

typedef struct Node
{
    int cod;
    char tipo;
    int prior;
    struct Node *link;
} Node;

Node *iniciaLista(Node *lista);
Node *insereFP(Node *L, int valor, int prior);
void exibeLO(Node *L);

int main()
{
    Node *listaVoos;
    listaVoos = iniciaLista(listaVoos);

    listaVoos = insereFP(listaVoos, 430, 3);
    listaVoos = insereFP(listaVoos, 558, 2);
    listaVoos = insereFP(listaVoos, 312, 3);
    listaVoos = insereFP(listaVoos, 400, 2);
    listaVoos = insereFP(listaVoos, 880, 2);
    listaVoos = insereFP(listaVoos, 224, 3);
    listaVoos = insereFP(listaVoos, 200, 1);
    listaVoos = insereFP(listaVoos, 482, 2);
    listaVoos = insereFP(listaVoos, 320, 3);
    listaVoos = insereFP(listaVoos, 578, 2);
    listaVoos = insereFP(listaVoos, 240, 3);
    listaVoos = insereFP(listaVoos, 180, 3);
    listaVoos = insereFP(listaVoos, 134, 1);

    exibeLO(listaVoos);
}

Node *iniciaLista(Node *lista)
{
    lista = NULL;
    return lista;
}

Node *insereFP(Node *L, int valor, int prior)
{
    Node *N, *P, *ANT;

    N = (Node *) malloc(sizeof(Node));
    N->cod = valor;
    N->prior = prior;

    if (L == NULL) {
        L = N;
        N->link = NULL;
    }
    else {
        P = L;

        while ((P != NULL) && (prior >= P->prior)) {
            ANT = P;
            P = P->link;
        }
        if (P == L) {
            N->link = L;
            L = N;
        }
        else {
            ANT->link = N;
            N->link = P;
        }
    }
    return L;
}

Node *removeFP(Node *L, int *cod, char *tipo, int *prior)
{
    Node *AUX;

    if (L != NULL)
    {
        *cod = L->cod;
        *tipo = L->tipo;
        *prior = L->prior;
        AUX = L;
        L = L->link;
        free(AUX);
    }
    return L;
}

void exibeLO(Node *L)
{
    Node *P;

    P = L; // P recebe o endereco do primeiro no da lista
    while (P != NULL)
    {
        printf("(#%d, %d) ", P->cod, P->prior);
        P = P->link;
    }
}