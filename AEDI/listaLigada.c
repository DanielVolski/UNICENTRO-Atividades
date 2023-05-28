#include <stdio.h>
#include <malloc.h>

typedef struct intNode //Estrutura que corresponde aos nós da lista ligada
{
    int num;                            //Armazena o número que será inserido na lista
    struct intNode *previousNumAddress; //Armazena o endereço do número anterior da lista
} intNode;

intNode *insert(intNode *L, int x); //Função que recebe uma lista e o número que deve ser inserido na lista
void *printList(intNode *L);        //Percorre uma lista e imprime os valores inteiros para cada um dos nós que a lista aponta

int main()
{
    intNode *list;

    for (int i = 0; i != 10; i++) //Insere números de 0 a 9 na lista
        list = insert(list, i);   //A cada iteração a list vai receber um novo nó com os valores solicitados

    printList(list);
}

intNode *insert(intNode *L, int x)
{
    intNode *N; //Variável auxiliar

    N = (intNode *)malloc(sizeof(intNode)); //Aloca memória para a variável auxiliar

    N->num = x;                //O membro num recebe o valor de x
    N->previousNumAddress = L; //O membro que armazena o endereço recebe o endereço de L
    L = N;                     //L recebe o endereço de N, que possui os valores definidos acima

    return L;
}

void *printList(intNode *L)
{
    while (L != NULL)
    {
        printf("%d\n", L->num); //Imprime o membro de L que armazena o numero inteiro 
        L = L->previousNumAddress; //L agora aponta para o endereço no dúmero anterior
    }
}