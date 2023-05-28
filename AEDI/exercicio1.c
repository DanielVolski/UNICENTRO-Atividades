#include<stdio.h>
#include<malloc.h>

int main() 
{
    int *p;
    p = (int *) malloc(10 * sizeof(int));

    if(p == NULL) {
        printf("Erro ao alocar memória!");
    } else {
        //Premissas
        *(p+0) = 1;
        *(p+1) = 2;
        //Preenche o ponteiro p com 10 valores da sequência Fibonacci
        for(int i=2; i<10; i++) {
            *(p+i) = *(p+(i-1)) + *(p+(i-2));
        }
        //Imprime os valores na tela
        for(int i=0; i<10; i++) {
            printf("%d\n", *(p+i));
        }
        //Libera o espaço de memória alocada
        free(p);
    }

    //Teste para ver o que acontece aós a memória ser liberada
    printf("\n");
    for(int i=0; i<10; i++) {
            printf("%d\n", *(p+i));
    }
}