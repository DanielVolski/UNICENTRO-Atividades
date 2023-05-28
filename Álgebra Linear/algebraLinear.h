#pragma once

/* Define a estrutura de dados da matriz */
typedef struct mat
{
    int linhas;
    int colunas;
    double **dados;
} mat;

/* Funções básicas */

mat *criaMatriz(int linhas, int colunas);
void imprimeMatriz(mat *matriz);
void liberaMatriz(mat *matriz);

/* Propriedades da Matriz */

int quadrada(mat *matriz);
mat *diagonalPrincipal(mat *matriz);
mat *diagonalSecundaria(mat *matriz);

/* Operações com matrizes */

mat *somaMatrizes(mat *matrizA, mat *matrizB, int sub);
mat *multMatrizes(mat *matrizA, mat *matrizB);