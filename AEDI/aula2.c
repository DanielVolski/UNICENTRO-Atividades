#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int *pi;
    pi = (int *) malloc(4);
    pi = NULL;

    if (pi) {
        *pi = 10;
        printf("Valor apontado para pi: %d\n", *pi);
        printf("Endereço de pi: %p\n", pi);
    } else {
        printf("Nao ha memoria para alocar \n");
    }
}