#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib/algebraLinear.h"
#define COL 3
#define LIN 3

void testeGaussSeidel();
mat *gaussSeidel(mat *A, mat *B, mat *x0, double delta, int it);
double maximoMatrizes(mat *matriz);
int criterioParada(mat *itAtual, mat *itAnterior, double delta);
mat *copiaMatriz(mat *matriz);

int main()
{
    testeGaussSeidel();
}

void testeGaussSeidel()
{
    mat *A = criaMatriz(LIN, COL);
    mat *B = criaMatriz(LIN, 1);
    mat *X = criaMatriz(LIN, 1);
    double delta = 0.05;

    A->dados[0][0] = 5;
    A->dados[0][1] = 1;
    A->dados[0][2] = 1;
    A->dados[1][0] = 3;
    A->dados[1][1] = 4;
    A->dados[1][2] = 1;
    A->dados[2][0] = 3;
    A->dados[2][1] = 3;
    A->dados[2][2] = 6;

    B->dados[0][0] = 5;
    B->dados[1][0] = 6;
    B->dados[2][0] = 0;

    X->dados[0][0] = 0;
    X->dados[1][0] = 0;
    X->dados[2][0] = 0;

    imprimeMatriz(gaussSeidel(A, B, X, 0.05, 3));
    //printf("%.2f", delta);
    //gaussSeidel(A, B, X, delta, 2);


    // X = gaussSeidel(A, B, delta);
    //  if (X->dados[0][0] != 1.0075)
    //      printf("ERRO! Valor de [0][0] e diferente do esperado.\n");
    //  if (X->dados[1][0] != 0.9912)
    //      printf("ERRO! Valor de [1][0] e diferente do esperado.\n");
    //  if (X->dados[2][0] != -0.9993)
    //      printf("ERRO! Valor de [2][0] e diferente do esperado.\n");

    liberaMatriz(A);
    liberaMatriz(B);
    liberaMatriz(X);
}

mat *gaussSeidel(mat *A, mat *B, mat *x0, double delta, int it)
{
    mat *anterior = criaMatriz(x0->linhas, x0->colunas);
    int rpt = 0;
    int i;
    int j;
    double soma;

    do
    {
        anterior = copiaMatriz(x0);
        for (i = 0; i < A->linhas; i++)
        {
            soma = 0;
            for (j = 0; j < A->colunas; j++)
            {
                if (i != j)
                    soma += (-A->dados[i][j] * (x0->dados[j][0]));
                if (i == j)
                    soma += B->dados[j][0];
            }
            x0->dados[i][0] = soma / A->dados[i][i];
        }
        rpt++;
    } while (criterioParada(x0, anterior, delta) || it < rpt);
    return x0;
}

//Busca o maior valor dentro de uma matriz para o cálculo do critério de parada
double maximoMatrizes(mat *matriz)
{
    double maximo = 0;

    for (int i = 0; i < matriz->linhas; i++)
        for (int j = 0; j < matriz->colunas; j++)
            if (fabs(matriz->dados[i][j]) > maximo)
                maximo = fabs(matriz->dados[i][j]);
            else
                continue;
    return maximo;
}

//Faz o erro relativo entre a iteração atual e anterior 
int criterioParada(mat *itAtual, mat *itAnterior, double delta)
{
    mat *diferencaMatrizes = criaMatriz(itAtual->linhas, itAtual->colunas);
    double maxItAtual = 0, maxDiferencaMatrizes = 0, diferenca = 0;

    for (int i = 0; i < diferencaMatrizes->linhas; i++)
        for (int j = 0; j < diferencaMatrizes->colunas; j++)
            diferencaMatrizes->dados[i][j] = fabs(itAtual->dados[i][j] - itAnterior->dados[i][j]);
    
    maxItAtual = maximoMatrizes(itAtual);
    maxDiferencaMatrizes = maximoMatrizes(diferencaMatrizes);
    diferenca = maxDiferencaMatrizes / maxItAtual;

    if (diferenca > delta)
        return 1;
    return 0;
}

//Copia os valores de uma matriz para outra
mat *copiaMatriz(mat *matriz)
{
    mat *copia = criaMatriz(matriz->linhas, matriz->colunas);

    for (int i = 0; i < matriz->linhas; i++)
        for (int j = 0; j < matriz->colunas; j++)
            copia->dados[i][j] = matriz->dados[i][j];

    return copia;
}