#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <malloc.h>
#include <stdio.h>

#define WIDTH 600
#define HEIGHT 600
#define DEPTH 32
#define rHEIGHT 50

typedef struct Retangulo
{
    sfRectangleShape *retangulo;
    sfVector2f tamanho;
    sfVector2f posicao;
    sfColor cor;
} Retangulo;

typedef struct Node
{
    Retangulo retangulo;
    struct Node *endereco;
} Node;

Retangulo criaRetangulo(Retangulo retangulo, float tamX, float tamY, float posX, float posY, sfColor cor);
Node *PUSH(Node *l, Retangulo retangulo);
Node *POP(Node *l, Retangulo *retangulo);

int main()
{
    int contador;
    // Preparando a janela
    sfVideoMode modo = {WIDTH, HEIGHT, DEPTH};
    sfRenderWindow *janela = sfRenderWindow_create(modo, "Torre de Hanoi", sfClose, NULL);
    sfRenderWindow_setKeyRepeatEnabled(janela, sfTrue);
    sfRenderWindow_setActive(janela, sfFalse);
    sfColor fundo = sfBlack;

    // Eventos e texto
    sfEvent evento;
    sfText *texto;
    sfFont *fonte;
    sfVector2f textoPos;
    texto = sfText_create();
    fonte = sfFont_createFromFile("/usr/share/fonts/opentype/urw-base35/URWGothic-DemiOblique.otf");
    sfText_setFont(texto, fonte);
    sfText_setCharacterSize(texto, 20);
    textoPos.x = (WIDTH / 2) - (sfText_getCharacterSize(texto) * 9 / 2);
    textoPos.y = HEIGHT / 4;
    sfText_setPosition(texto, textoPos);

    // Cores
    sfColor cinza = {194, 197, 204, 100};
    sfColor branco = {255, 255, 255, 100};

    // Criando os discos
    Retangulo rMaior, rMedio, rMenor;
    rMaior = criaRetangulo(rMaior, WIDTH / 3, rHEIGHT, 0, HEIGHT - rHEIGHT, sfBlue);
    rMedio = criaRetangulo(rMedio, (WIDTH / 3) - (WIDTH / 20), rHEIGHT, (WIDTH / 40), HEIGHT - rHEIGHT * 2, sfGreen);
    rMenor = criaRetangulo(rMenor, (WIDTH / 3) - (WIDTH / 10), rHEIGHT, (WIDTH / 20), HEIGHT - rHEIGHT * 3, sfRed);

    // Criando as torres
    Node *pilhaTorre1 = NULL, *pilhaTorre2 = NULL, *pilhaTorre3 = NULL, *inicioPilha = NULL;
    Retangulo torre1, torre2, torre3;
    torre1 = criaRetangulo(torre1, 10, HEIGHT / 2, WIDTH / 4, HEIGHT / 2, cinza);
    torre2 = criaRetangulo(torre2, 10, HEIGHT / 2, WIDTH / 2, HEIGHT / 2, cinza);
    torre3 = criaRetangulo(torre3, 10, HEIGHT / 2, WIDTH, HEIGHT / 2, cinza);

    pilhaTorre1 = PUSH(pilhaTorre1, rMaior);
    pilhaTorre1 = PUSH(pilhaTorre1, rMedio);
    pilhaTorre1 = PUSH(pilhaTorre1, rMenor);

    // Criando o retangulo de seleção de torre
    Retangulo selecao;
    Node *noSelecao = NULL;
    selecao = criaRetangulo(selecao, WIDTH / 3, HEIGHT / 2, 0, HEIGHT / 2, branco);

    while (sfRenderWindow_isOpen(janela))
    {
        while (sfRenderWindow_pollEvent(janela, &evento))
        {
            // Piscina de eventos
            if (evento.type == sfEvtClosed)
                sfRenderWindow_close(janela);
            else if (evento.type == sfEvtKeyPressed && contador != 3)
            {
                sfText_setString(texto, "");
                if (evento.key.code == sfKeyEscape) {
                    sfRenderWindow_close(janela);
                }
                if (evento.key.code == sfKeyLeft)
                {
                    // Move a seleção para a esquerda
                    selecao.posicao.x -= selecao.tamanho.x;
                    if (selecao.posicao.x < 0)
                        selecao.posicao.x = WIDTH - selecao.tamanho.x;
                    sfRectangleShape_setPosition(selecao.retangulo, selecao.posicao);
                    printf("Movendo para a esquerda, X: %f Y: %f\n", selecao.posicao.x, selecao.posicao.y);
                }
                else if (evento.key.code == sfKeyRight)
                {
                    // Move a seleção para a direita
                    selecao.posicao.x += selecao.tamanho.x;
                    if (selecao.posicao.x >= WIDTH)
                        selecao.posicao.x = 0;
                    sfRectangleShape_setPosition(selecao.retangulo, selecao.posicao);
                    printf("Movendo para a direita, X: %f Y: %f\n", selecao.posicao.x, selecao.posicao.y);
                }
                else if (evento.key.code == sfKeyEnter && noSelecao == NULL)
                {
                    if (selecao.posicao.x == 0 && pilhaTorre1 != NULL)
                    {
                        noSelecao = PUSH(noSelecao, pilhaTorre1->retangulo);
                        pilhaTorre1 = POP(pilhaTorre1, &pilhaTorre1->retangulo);
                        printf("Retirado da pilha 1 e colocado na seleção\n");
                    }
                    if (selecao.posicao.x == WIDTH / 3 && pilhaTorre2 != NULL)
                    {
                        noSelecao = PUSH(noSelecao, pilhaTorre2->retangulo);
                        pilhaTorre2 = POP(pilhaTorre2, &pilhaTorre2->retangulo);
                        printf("Retirado da pilha 2 e colocado na seleção\n");
                    }
                    if (selecao.posicao.x == WIDTH - selecao.tamanho.x && pilhaTorre3 != NULL)
                    {
                        noSelecao = PUSH(noSelecao, pilhaTorre3->retangulo);
                        pilhaTorre3 = POP(pilhaTorre3, &pilhaTorre3->retangulo);
                        printf("Retirado da pilha 3 e colocado na seleção\n");
                    }
                }
                else if (evento.key.code == sfKeyEnter && noSelecao != NULL)
                {
                    if (selecao.posicao.x == 0)
                    {
                        if (pilhaTorre1 != NULL && pilhaTorre1->retangulo.tamanho.x > noSelecao->retangulo.tamanho.x)
                        {
                            noSelecao->retangulo.posicao.x = selecao.posicao.x + (selecao.tamanho.x - noSelecao->retangulo.tamanho.x) / 2;
                            noSelecao->retangulo.posicao.y = pilhaTorre1->retangulo.posicao.y - rHEIGHT;
                            sfRectangleShape_setPosition(noSelecao->retangulo.retangulo, noSelecao->retangulo.posicao);
                            pilhaTorre1 = PUSH(pilhaTorre1, noSelecao->retangulo);
                            noSelecao = POP(noSelecao, &noSelecao->retangulo);
                            printf("Colocado na pilha 1\n");
                        }
                        else if (pilhaTorre1 == NULL)
                        {
                            noSelecao->retangulo.posicao.x = selecao.posicao.x + (selecao.tamanho.x - noSelecao->retangulo.tamanho.x) / 2;
                            noSelecao->retangulo.posicao.y = HEIGHT - rHEIGHT;
                            sfRectangleShape_setPosition(noSelecao->retangulo.retangulo, noSelecao->retangulo.posicao);
                            pilhaTorre1 = PUSH(pilhaTorre1, noSelecao->retangulo);
                            noSelecao = POP(noSelecao, &noSelecao->retangulo);
                            printf("Colocado na pilha 1\n");
                        }
                        else
                        {
                            sfText_setString(texto, "Jogada invalida!");
                            printf("Invalido\n");
                        }
                    }
                    if (selecao.posicao.x == WIDTH / 3)
                    {
                        if (pilhaTorre2 != NULL && pilhaTorre2->retangulo.tamanho.x > noSelecao->retangulo.tamanho.x)
                        {
                            noSelecao->retangulo.posicao.x = selecao.posicao.x + (selecao.tamanho.x - noSelecao->retangulo.tamanho.x) / 2;
                            noSelecao->retangulo.posicao.y = pilhaTorre2->retangulo.posicao.y - rHEIGHT;
                            sfRectangleShape_setPosition(noSelecao->retangulo.retangulo, noSelecao->retangulo.posicao);
                            pilhaTorre2 = PUSH(pilhaTorre2, noSelecao->retangulo);
                            noSelecao = POP(noSelecao, &noSelecao->retangulo);
                            printf("Colocado na pilha 2\n");
                        }
                        else if (pilhaTorre2 == NULL)
                        {
                            noSelecao->retangulo.posicao.x = selecao.posicao.x + (selecao.tamanho.x - noSelecao->retangulo.tamanho.x) / 2;
                            noSelecao->retangulo.posicao.y = HEIGHT - rHEIGHT;
                            sfRectangleShape_setPosition(noSelecao->retangulo.retangulo, noSelecao->retangulo.posicao);
                            pilhaTorre2 = PUSH(pilhaTorre2, noSelecao->retangulo);
                            noSelecao = POP(noSelecao, &noSelecao->retangulo);
                            printf("Colocado na pilha 2\n");
                        }
                        else
                        {
                            sfText_setString(texto, "Jogada invalida!");
                            printf("Invalido\n");
                        }
                    }
                    if (selecao.posicao.x == WIDTH - selecao.tamanho.x)
                    {
                        if (pilhaTorre3 != NULL && pilhaTorre3->retangulo.tamanho.x > noSelecao->retangulo.tamanho.x)
                        {
                            noSelecao->retangulo.posicao.x = selecao.posicao.x + (selecao.tamanho.x - noSelecao->retangulo.tamanho.x) / 2;
                            noSelecao->retangulo.posicao.y = pilhaTorre3->retangulo.posicao.y - rHEIGHT;
                            sfRectangleShape_setPosition(noSelecao->retangulo.retangulo, noSelecao->retangulo.posicao);
                            pilhaTorre3 = PUSH(pilhaTorre3, noSelecao->retangulo);
                            noSelecao = POP(noSelecao, &noSelecao->retangulo);
                            printf("Colocado na pilha 3\n");
                        }
                        else if (pilhaTorre3 == NULL)
                        {
                            noSelecao->retangulo.posicao.x = selecao.posicao.x + (selecao.tamanho.x - noSelecao->retangulo.tamanho.x) / 2;
                            noSelecao->retangulo.posicao.y = HEIGHT - rHEIGHT;
                            sfRectangleShape_setPosition(noSelecao->retangulo.retangulo, noSelecao->retangulo.posicao);
                            pilhaTorre3 = PUSH(pilhaTorre3, noSelecao->retangulo);
                            noSelecao = POP(noSelecao, &noSelecao->retangulo);
                            printf("Colocado na pilha 3\n");
                        }
                        else
                        {
                            printf("Invalido\n");
                            sfText_setString(texto, "Jogada invalida!");
                        }
                    }
                    
                }
            }
        }

        // Limpar, desenhar e mostrar
        sfRenderWindow_clear(janela, fundo);

        //sfRenderWindow_drawRectangleShape(janela, torre1.retangulo, NULL);
        //sfRenderWindow_drawRectangleShape(janela, torre2.retangulo, NULL);
        //sfRenderWindow_drawRectangleShape(janela, torre3.retangulo, NULL);

        sfRenderWindow_drawText(janela, texto, NULL);

        inicioPilha = pilhaTorre1;
        while (pilhaTorre1 != NULL)
        {
            sfRenderWindow_drawRectangleShape(janela, pilhaTorre1->retangulo.retangulo, NULL);
            pilhaTorre1 = pilhaTorre1->endereco;
        }
        pilhaTorre1 = inicioPilha;

        inicioPilha = pilhaTorre2;
        while (pilhaTorre2 != NULL)
        {
            sfRenderWindow_drawRectangleShape(janela, pilhaTorre2->retangulo.retangulo, NULL);
            pilhaTorre2 = pilhaTorre2->endereco;
        }
        pilhaTorre2 = inicioPilha;

        inicioPilha = pilhaTorre3;
        contador = 0;
        while (pilhaTorre3 != NULL)
        {
            sfRenderWindow_drawRectangleShape(janela, pilhaTorre3->retangulo.retangulo, NULL);
            pilhaTorre3 = pilhaTorre3->endereco;
            contador++;
            if(contador == 3) {
                sfText_setString(texto, "Ganhou!");
                sfRenderWindow_drawText(janela, texto, NULL);
                sfRenderWindow_close(janela);
            }

                
        }
        pilhaTorre3 = inicioPilha;

        sfRenderWindow_drawRectangleShape(janela, selecao.retangulo, NULL);

        sfRenderWindow_display(janela);
    }

    sfRectangleShape_destroy(rMaior.retangulo);
    sfRectangleShape_destroy(rMedio.retangulo);
    sfRectangleShape_destroy(rMenor.retangulo);
    sfRectangleShape_destroy(torre1.retangulo);
    sfRectangleShape_destroy(torre2.retangulo);
    sfRectangleShape_destroy(torre3.retangulo);
    sfRectangleShape_destroy(selecao.retangulo);
    sfText_destroy(texto);
    sfFont_destroy(fonte);
    sfRenderWindow_destroy(janela);

    return 0;
}

Retangulo criaRetangulo(Retangulo retangulo, float tamX, float tamY, float posX, float posY, sfColor cor)
{
    retangulo.retangulo = sfRectangleShape_create();

    retangulo.tamanho.x = tamX;
    retangulo.tamanho.y = tamY;
    sfRectangleShape_setSize(retangulo.retangulo, retangulo.tamanho);

    retangulo.posicao.x = posX;
    retangulo.posicao.y = posY;
    sfRectangleShape_setPosition(retangulo.retangulo, retangulo.posicao);

    retangulo.cor = cor;
    sfRectangleShape_setFillColor(retangulo.retangulo, cor);

    return retangulo;
}

Node *PUSH(Node *l, Retangulo retangulo)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    n->retangulo = retangulo;
    n->endereco = l;
    l = n;
    return l;
}

Node *POP(Node *l, Retangulo *retangulo)
{
    Node *n;
    if (l != NULL)
    {
        *retangulo = l->retangulo;
        n = l;
        l = l->endereco;
        free(n);
    }
    return l;
}