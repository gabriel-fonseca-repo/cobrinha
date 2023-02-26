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

void imprimirCoordenada(int x, int y, int cor)
{
    COORD coord;
    HANDLE hOut;

    coord.X = x;
    coord.Y = y;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hOut, cor);
    SetConsoleCursorPosition(hOut, coord);
    printf("%c", 219);

    SetConsoleTextAttribute(hOut, 7);
}

void imprimirQuadro()
{
    int i;
    for (i = 0; i < LARGURA; i++)
    {
        imprimirCoordenada(i, 0, 7);
        imprimirCoordenada(i, ALTURA - 1, 7);
    }
    for (i = 0; i < ALTURA; i++)
    {
        imprimirCoordenada(0, i, 7);
        imprimirCoordenada(LARGURA - 1, i, 7);
    }
}

void imprimirMatriz()
{
    int i, j;
    for (i = 0; i < ALTURA; i++)
    {
        for (j = 0; j < LARGURA; j++)
        {
            printf("%d\t", M[i][j]);
            if (j == LARGURA)
            {
                printf("\n");
            }
        }
    }
}

void *handlePlayer(void *n)
{
    cobrinha player = *(cobrinha *)n;

    int buffer[ALTURA * LARGURA][2] = {{0}};
    int cima = 0, baixo = 0, esquerda = 0, direita = 0;
    int x0 = player.x0;
    int y0 = player.y0;
    int i = y0;
    int j = x0;
    int iMovimento = 0;
    int iApagar, jApagar;

    while (i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
    {

        cima = GetAsyncKeyState(player.teclaCima);
        baixo = GetAsyncKeyState(player.teclaBaixo);
        esquerda = GetAsyncKeyState(player.teclaEsquerda);
        direita = GetAsyncKeyState(player.teclaDireita);

        if (cima)
        {
            esquerda = 0;
            direita = 0;
            while (!esquerda && !direita && i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
            {
                buffer[iMovimento][1] = i;
                buffer[iMovimento][2] = j;
                if (iMovimento >= TAMANHO_INICIAL)
                {
                    iApagar = buffer[iMovimento - TAMANHO_INICIAL][1];
                    jApagar = buffer[iMovimento - TAMANHO_INICIAL][2];
                    M[iApagar][jApagar] = 0;
                    imprimirCoordenada(jApagar, iApagar, 0);
                    buffer[iMovimento - TAMANHO_INICIAL][1] = 0;
                    buffer[iMovimento - TAMANHO_INICIAL][2] = 0;
                }

                M[i][j] = 1;
                imprimirCoordenada(j, i, player.color);
                Sleep(50);
                i--;
                iMovimento++;

                esquerda = GetAsyncKeyState(player.teclaEsquerda);
                direita = GetAsyncKeyState(player.teclaDireita);
            }
        }

        if (baixo)
        {
            esquerda = 0;
            direita = 0;
            while (!esquerda && !direita && i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
            {
                buffer[iMovimento][1] = i;
                buffer[iMovimento][2] = j;
                if (iMovimento >= TAMANHO_INICIAL)
                {
                    iApagar = buffer[iMovimento - TAMANHO_INICIAL][1];
                    jApagar = buffer[iMovimento - TAMANHO_INICIAL][2];
                    M[iApagar][jApagar] = 0;
                    imprimirCoordenada(jApagar, iApagar, 0);
                    buffer[iMovimento - TAMANHO_INICIAL][1] = 0;
                    buffer[iMovimento - TAMANHO_INICIAL][2] = 0;
                }

                M[i][j] = 1;
                imprimirCoordenada(j, i, 11);
                Sleep(50);
                i++;
                iMovimento++;

                esquerda = GetAsyncKeyState(player.teclaEsquerda);
                direita = GetAsyncKeyState(player.teclaDireita);
            }
        }

        if (direita)
        {
            baixo = 0;
            cima = 0;
            while (!cima && !baixo && i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
            {
                buffer[iMovimento][1] = i;
                buffer[iMovimento][2] = j;
                if (iMovimento >= TAMANHO_INICIAL)
                {
                    iApagar = buffer[iMovimento - TAMANHO_INICIAL][1];
                    jApagar = buffer[iMovimento - TAMANHO_INICIAL][2];
                    M[iApagar][jApagar] = 0;
                    imprimirCoordenada(jApagar, iApagar, 0);
                    buffer[iMovimento - TAMANHO_INICIAL][1] = 0;
                    buffer[iMovimento - TAMANHO_INICIAL][2] = 0;
                }

                M[i][j] = 1;
                imprimirCoordenada(j, i, 11);
                Sleep(50);
                j++;
                iMovimento++;

                cima = GetAsyncKeyState(player.teclaCima);
                baixo = GetAsyncKeyState(player.teclaBaixo);
            }
        }

        if (esquerda)
        {
            baixo = 0;
            cima = 0;
            while (!cima && !baixo && i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
            {
                buffer[iMovimento][1] = i;
                buffer[iMovimento][2] = j;
                if (iMovimento >= TAMANHO_INICIAL)
                {
                    iApagar = buffer[iMovimento - TAMANHO_INICIAL][1];
                    jApagar = buffer[iMovimento - TAMANHO_INICIAL][2];
                    M[iApagar][jApagar] = 0;
                    imprimirCoordenada(jApagar, iApagar, 0);
                    buffer[iMovimento - TAMANHO_INICIAL][1] = 0;
                    buffer[iMovimento - TAMANHO_INICIAL][2] = 0;
                }

                M[i][j] = 1;
                imprimirCoordenada(j, i, 11);
                Sleep(50);
                j--;
                iMovimento++;

                cima = GetAsyncKeyState(player.teclaCima);
                baixo = GetAsyncKeyState(player.teclaBaixo);
            }
        }
    }
}

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