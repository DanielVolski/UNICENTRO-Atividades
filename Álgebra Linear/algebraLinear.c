#include <stdlib.h>
#include <stdio.h>
#include "algebraLinear.h"

/* Funções básicas */

mat *criaMatriz(int linhas, int colunas)
{
    if (linhas == 0 || colunas == 0)
    {
        printf("A matriz não pode ser alocada sem colunas ou linhas\n");
        return NULL;
    }
    else
    {
        mat *matriz = calloc(1, sizeof(*matriz));
        matriz->linhas = linhas;
        matriz->colunas = colunas;
        matriz->dados = calloc(matriz->linhas, sizeof(*matriz->dados));

        for (int i = 0; i < matriz->linhas; i++)
            matriz->dados[i] = calloc(matriz->colunas, sizeof(**matriz->dados));
        return matriz;
    }
}

void imprimeMatriz(mat *matriz)
{
    if (matriz != NULL)
    {
        for (int i = 0; i < matriz->linhas; i++)
        {
            for (int j = 0; j < matriz->colunas; j++)
                printf("%.10f ", matriz->dados[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("Matriz vazia ou inválida!\n");
    }
}

void liberaMatriz(mat *matriz)
{
    for (int i = 0; i < matriz->linhas; i++)
        free(matriz->dados[i]); // Desaloca as linhas
    free(matriz->dados);        // Desaloca as colunas
    free(matriz);               // Desaloca a estrutura de dados
}

/* Propriedades da matriz */

int quadrada(mat *matriz)
{
    return matriz->colunas == matriz->linhas;
}

mat *diagonalPrincipal(mat *matriz)
{
    if (quadrada(matriz))
    {
        mat *diagPrincipal = criaMatriz(1, matriz->colunas);
        for (int i = 0; i < matriz->linhas; i++)
            for (int j = 0; j < matriz->colunas; j++)
                if (i == j)
                    diagPrincipal->dados[0][i] = matriz->dados[i][j];
        return diagPrincipal;
    }
    printf("A matriz não é quadrada!\n");
    return NULL;
}

mat *diagonalSecundaria(mat *matriz)
{
    if (quadrada(matriz))
    {
        mat *diagSecundaria = criaMatriz(1, matriz->colunas);
        for (int i = 0; i < matriz->linhas; i++)
            for (int j = 0; j < matriz->colunas; j++)
                if (j == matriz->colunas - 1 - i)
                    diagSecundaria->dados[0][i] = matriz->dados[i][j];
        return diagSecundaria;
    }
    printf("A matriz não é quadrada!\n");
    return NULL;
}

/* Operações com matrizes */

mat *somaMatrizes(mat *matrizA, mat *matrizB, int sub)
{
    if (quadrada(matrizA) && quadrada(matrizB))
    {
        if (sub == 0) {
            mat *resultante = criaMatriz(matrizA->linhas, matrizA->colunas);
            for (int i = 0; i < matrizA->linhas; i++)
                for (int j = 0; j < matrizA->colunas; j++)
                    resultante->dados[i][j] = matrizA->dados[i][j] + matrizB->dados[i][j];
            return resultante;
        }
        if (sub == 1)
        {
            mat *resultante = criaMatriz(matrizA->linhas, matrizA->colunas);
            for (int i = 0; i < matrizA->linhas; i++)
                for (int j = 0; j < matrizA->colunas; j++)
                    resultante->dados[i][j] = matrizA->dados[i][j] - matrizB->dados[i][j];
            return resultante;
        }
    }
    else
    {
        printf("As matrizes não são de mesma ordem!\n");
        return NULL;
    }
}

mat *multMatrizes(mat *matrizA, mat *matrizB)
{
    if (matrizA->colunas == matrizB->linhas)
    {
        mat *resultante = criaMatriz(matrizA->linhas, matrizB->colunas);

        for (int i = 0; i < resultante->linhas; i++)
            for (int j = 0; j < resultante->colunas; j++)
                for (int k = 0; k < matrizA->colunas; k++)
                    resultante->dados[i][j] += matrizA->dados[i][k] * matrizB->dados[k][j];
        return resultante;
    }
    else
    {
        printf("Matrizes inválidas");
        return NULL;
    }
}