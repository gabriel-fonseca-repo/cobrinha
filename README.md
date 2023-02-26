# Cobrinha em C - Aprendizagem de sistemas operacionais.

## Clone do jogo da cobrinha implementado em C utilizando-se da api nativa do windows ```<windows.h>``` e ```<pthread.h>``` com intúito de aprender tecnologias a nível de sistema operacional.

```c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>

#define ALTURA 30
#define LARGURA 100
#define TAMANHO_INICIAL 10

typedef struct info_jogador
{
    int teclaCima;
    int teclaBaixo;
    int teclaEsquerda;
    int teclaDireita;
    int x0;
    int y0;
    int color;
} cobrinha;

int M[ALTURA][LARGURA] = {{0}};

void imprimirCoordenada(int x, int y, int cor){}
void imprimirQuadro(){}
void imprimirMatriz(){}
void *handlePlayer(void *n){}

int main()
{
    pthread_t t1, t2;

    cobrinha player1, player2;

    player1.color = 1;
    player1.teclaCima = VK_UP;
    player1.teclaEsquerda = VK_LEFT;
    player1.teclaBaixo = VK_DOWN;
    player1.teclaDireita = VK_RIGHT;
    player1.x0 = (int)(0.75 * LARGURA);
    player1.y0 = (int)(0.25 * ALTURA);

    player2.color = 11;
    player2.teclaCima = 87; // W
    player2.teclaEsquerda = 65; // A
    player2.teclaBaixo = 83; // S
    player2.teclaDireita = 68; // D
    player2.x0 = (int)(0.25 * LARGURA);
    player2.y0 = (int)(0.75 * ALTURA);

    system("cls");
    imprimirQuadro();

    pthread_create(&t1, NULL, handlePlayer, &player1);
    pthread_create(&t2, NULL, handlePlayer, &player2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
```