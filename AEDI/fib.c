#include<stdio.h>
#include<malloc.h>

typedef struct typeNode {
    int num;
    struct typeNode *previousNumAddress;
} intNode;

intNode* insertInt(intNode *L, int x);
void printList(intNode *L);

int main()
{
    intNode *list;

    list = insertInt(list, 1);
    list = insertInt(list, 2);

    for (int i = 2; i < 10; i++)
        list = insertInt(list, (list->num + list->previousNumAddress->num));
    
    printList(list);
}

intNode* insertInt(intNode *L, int x) {
    intNode *N;

    N = (intNode *) malloc(sizeof(intNode));
    
    N->num = x;
    N->previousNumAddress = L;
    L = N;

    return (L);
}

void printList(intNode *L) {
    intNode *N = L; 
    
    while(N != NULL) {
        printf("%d\n", N->num);
        N = N->previousNumAddress;
    }
}