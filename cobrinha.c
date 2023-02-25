#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>

#define ALTURA 25
#define LARGURA 75
#define TAMANHO_INICIAL 10

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
void *handlePlayer2(void *n)
{
    int buffer[ALTURA * LARGURA][2] = {{0}};
    int cima = 0, baixo = 0, esquerda = 0, direita = 0;
    int x0 = (int)(0.75 * LARGURA);
    int y0 = (int)(0.25 * ALTURA);
    int i = y0;
    int j = x0;
    int iMovimento = 0;
    int iApagar, jApagar;
    int color = 1;

    system("cls");
    imprimirQuadro();

    while (i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
    {

        cima = GetAsyncKeyState(87);
        baixo = GetAsyncKeyState(83);
        esquerda = GetAsyncKeyState(65);
        direita = GetAsyncKeyState(68);

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
                imprimirCoordenada(j, i, color);
                Sleep(50);
                i--;
                iMovimento++;

                esquerda = GetAsyncKeyState(65);
                direita = GetAsyncKeyState(68);
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
                imprimirCoordenada(j, i, color);
                Sleep(50);
                i++;
                iMovimento++;

                esquerda = GetAsyncKeyState(65);
                direita = GetAsyncKeyState(68);
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
                imprimirCoordenada(j, i, color);
                Sleep(50);
                j++;
                iMovimento++;

                cima = GetAsyncKeyState(87);
                baixo = GetAsyncKeyState(83);
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
                imprimirCoordenada(j, i, color);
                Sleep(50);
                j--;
                iMovimento++;

                cima = GetAsyncKeyState(87);
                baixo = GetAsyncKeyState(83);
            }
        }
    }
}
void *handlePlayer1(void *n)
{
    int numero = *(int *)n;

    int buffer[ALTURA * LARGURA][2] = {{0}};
    int cima = 0, baixo = 0, esquerda = 0, direita = 0;
    int x0 = (int)(0.25 * LARGURA);
    int y0 = (int)(0.75 * ALTURA);
    int i = y0;
    int j = x0;
    int iMovimento = 0;
    int iApagar, jApagar;

    system("cls");
    imprimirQuadro();

    while (i < ALTURA - 1 && i >= 1 && j < LARGURA - 1 && j > 1 && !M[i][j])
    {

        cima = GetAsyncKeyState(VK_UP);
        baixo = GetAsyncKeyState(VK_DOWN);
        esquerda = GetAsyncKeyState(VK_LEFT);
        direita = GetAsyncKeyState(VK_RIGHT);

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
                imprimirCoordenada(j, i, 11);
                Sleep(50);
                i--;
                iMovimento++;

                esquerda = GetAsyncKeyState(VK_LEFT);
                direita = GetAsyncKeyState(VK_RIGHT);
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

                esquerda = GetAsyncKeyState(VK_LEFT);
                direita = GetAsyncKeyState(VK_RIGHT);
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

                cima = GetAsyncKeyState(VK_UP);
                baixo = GetAsyncKeyState(VK_DOWN);
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

                cima = GetAsyncKeyState(VK_UP);
                baixo = GetAsyncKeyState(VK_DOWN);
            }
        }
    }
}

int main()
{

    pthread_t t1, t2;
    int n1 = 1, n2 = 2;

    pthread_create(&t1, NULL, handlePlayer1, &n1);
    pthread_create(&t2, NULL, handlePlayer2, &n2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}