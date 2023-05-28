#include<stdio.h>
#include<malloc.h>

typedef struct typeNode {
    int num;
    struct typeNode *nextAddress;
} Node;

Node* insert(Node *L, int x);
void printList(Node *L);

int main()
{
    Node *list;
    list = NULL;

    list = insert(list, 6);
    list = insert(list, 12);
    printList(list);
}

Node* insert(Node *L, int x) {
    Node *N;

    N = (Node *) malloc(sizeof(Node));

    N->num = x;
    N->nextAddress = L;

    L = N;
    return L;
}


void printList(Node *L) {
    while(L != NULL) {
        printf("%d ", L->num);
        L = L->nextAddress;
    }
}