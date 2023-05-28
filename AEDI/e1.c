#include <stdio.h>
#include <malloc.h>

typedef struct intNode
{
    int num;
    struct intNode *previousAddress;
} intNode;

intNode *insert(intNode *n, int value);
void *printLastValue(intNode *n);
void *printList(intNode *n);

int main()
{
    intNode *n;

    n = insert(n, 1);
    n = insert(n, 23);

    printLastValue(n);
}

intNode *insert(intNode *n, int value)
{
    intNode *N;
    N = (intNode *)malloc(sizeof(intNode));

    N->num = value;
    N->previousAddress = n;

    n = N;
    //printf("Executou o insert\n");
    return (n);
}

void *printLastValue(intNode *n)
{
    while (1)
    {
        if (n->previousAddress == NULL) //Verifica se o membro que armazena o endereço é nulo
        {
            printf("%d", n->num); //Caso seja nulo, significa que este é o último valor da lista então é feita a exibição
            break;
        }
        n = n->previousAddress;
    }
}

void *printList(intNode *n)
{
    //printf("Executou o print\n");
    while (n != NULL)
    {
        printf("%d\n", n->num);
        n = n->previousAddress;
    }
}