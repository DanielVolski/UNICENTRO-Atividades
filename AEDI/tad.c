#include<stdio.h>

//Structs
typedef struct 
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct 
{
    char *nome;
    char *sobrenome;
    Data dataNascimento;
} Cadastro;

//Protótipos de funções
void mostraDados(Cadastro cadastro);
void mudaNome(Cadastro *cadastro, char *nome, char *sobrenome);
void mudaDataNascimento(Cadastro *cadastro, int dia, int mes, int ano);

int main()
{
    Cadastro cadastro;
    cadastro.nome = "Daniel";
    cadastro.sobrenome = "Volski";
    cadastro.dataNascimento.dia = 10;
    cadastro.dataNascimento.mes = 4;
    cadastro.dataNascimento.ano = 2002;

    mostraDados(cadastro);
    mudaNome(&cadastro, "Jubileu", "Biro Liro");
    mudaDataNascimento(&cadastro, 25, 7, 2021);
    mostraDados(cadastro);
}

//Funções
void mostraDados(Cadastro cadastro)
{
    printf("------------------------------\n");
    printf("Nome completo: %s %s\n", cadastro.nome, cadastro.sobrenome);
    printf("Data de nascimento: %d/%d/%d\n", cadastro.dataNascimento.dia, cadastro.dataNascimento.mes, cadastro.dataNascimento.ano);
    printf("------------------------------\n");
}

void mudaNome(Cadastro *cadastro, char *nome, char *sobrenome)
{
    cadastro->nome = nome;
    cadastro->sobrenome = sobrenome;
}

void mudaDataNascimento(Cadastro *cadastro, int dia, int mes, int ano)
{
    cadastro->dataNascimento.dia = dia;
    cadastro->dataNascimento.mes = mes;
    cadastro->dataNascimento.ano = ano;
}