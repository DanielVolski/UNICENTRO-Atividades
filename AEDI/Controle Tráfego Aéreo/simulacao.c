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
Node *insereFP(Node *L, int cod, char tipo, int prior);
Node *removeFP(Node *L, int *cod, char *tipo, int *prior);
Node *insereFilaChegada(Node *L, int cod, char tipo, int prior);
void delay(int ms);
void exibeLO(Node *L);

int main()
{
    Node *listaVoos, *emEspera;
    int voo, cod, prior, tempo, true = 1;
    char tipo;

    listaVoos = iniciaLista(listaVoos);
    emEspera = iniciaLista(emEspera);

    listaVoos = insereFilaChegada(listaVoos, 430, 'D', 3);
    listaVoos = insereFilaChegada(listaVoos, 558, 'P', 2);
    listaVoos = insereFilaChegada(listaVoos, 312, 'D', 3);
    listaVoos = insereFilaChegada(listaVoos, 400, 'P', 2);
    listaVoos = insereFilaChegada(listaVoos, 880, 'P', 2);
    listaVoos = insereFilaChegada(listaVoos, 224, 'D', 3);
    listaVoos = insereFilaChegada(listaVoos, 200, 'P', 1);
    listaVoos = insereFilaChegada(listaVoos, 482, 'P', 2);
    listaVoos = insereFilaChegada(listaVoos, 320, 'D', 3);
    listaVoos = insereFilaChegada(listaVoos, 578, 'P', 2);
    listaVoos = insereFilaChegada(listaVoos, 240, 'D', 3);
    listaVoos = insereFilaChegada(listaVoos, 180, 'D', 3);
    listaVoos = insereFilaChegada(listaVoos, 134, 'D', 1);

    printf("Mostra a lista de voos que devem chegar na seguinte ordem: \n");
    exibeLO(listaVoos);

    for (tempo = 1; true; tempo++)
    {
        printf("\n*******************************************************************************************");
        printf("\n***********************************  UNIDADE DE TEMPO: %d *********************************", tempo);
        printf("\n*******************************************************************************************");
        for (voo = 1; voo <= 3; voo++)
        {
            if (listaVoos != NULL)
            {
                listaVoos = removeFP(listaVoos, &cod, &tipo, &prior);
                emEspera = insereFP(emEspera, cod, tipo, prior);
            }
        }
        printf("\nVoos em espera: ");
        exibeLO(emEspera);
        if (tempo % 2 && true)
        {
            for (int i = 1; i <= 2; i++)
            {
                if (emEspera != NULL)
                {
                    emEspera = removeFP(emEspera, &cod, &tipo, &prior);
                    switch (tipo)
                    {
                    case 80:
                        printf("\nVoo #%d realizando pouso na pista %d\n", cod, i);
                        delay(3000);
                        tempo += 3;
                        break;
                    case 68:
                        printf("\nVoo #%d realizando decolagem na pista %d\n", cod, i);
                        delay(3000);
                        tempo += 3;
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    true = 0;
                    printf("\nTodos os voos já foram atendidos!");
                }
            }
            if (listaVoos != NULL)
            {
                printf("\nVoos em espera: ");
                exibeLO(emEspera);
            }
        }
    }
    return 0;
}

Node *iniciaLista(Node *lista)
{
    lista = NULL;
    return lista;
}

Node *insereFP(Node *L, int cod, char tipo, int prior)
{
    Node *N, *P, *ANT;

    N = (Node *)malloc(sizeof(Node));
    N->cod = cod;
    N->tipo = tipo;
    N->prior = prior;

    if (L == NULL)
    {
        L = N;
        N->link = NULL;
    }
    else
    {
        P = L;

        while ((P != NULL) && (prior >= P->prior))
        {
            ANT = P;
            P = P->link;
        }
        if (P == L)
        {
            N->link = L;
            L = N;
        }
        else
        {
            ANT->link = N;
            N->link = P;
        }
    }
    return L;
}

Node *insereFilaChegada(Node *L, int cod, char tipo, int prior)
{
    Node *P, *N;

    N = (Node *)malloc(sizeof(Node));
    N->cod = cod;
    N->tipo = tipo;
    N->prior = prior;
    N->link = NULL;

    if (L == NULL)
    {
        L = N;
    }
    else
    {
        P = L;

        while (P->link != NULL)
        {
            P = P->link;
        }
        P->link = N;
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

void delay(int milliseconds)
{
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause)
        now = clock();
}