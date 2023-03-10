#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ALTURA 50
#define LARGURA 150
#define TAMANHO_INICIAL 3

int M[ALTURA][LARGURA] = {{0}};

void imprimirCoordenada(int x, int y, int cor)
{
    COORD coord;
    HANDLE hOut;

    coord.X = x;
    coord.Y = y;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hOut,cor);
    SetConsoleCursorPosition(hOut,coord);
    printf("%c",219);

    SetConsoleTextAttribute(hOut,7);
}

void imprimirQuadro()
{
    int i;
    for(i=0; i<LARGURA; i++)
    {
        imprimirCoordenada(i,0,7);
        imprimirCoordenada(i,ALTURA-1,7);
    }
    for(i=0; i<ALTURA; i++)
    {
        imprimirCoordenada(0,i,7);
        imprimirCoordenada(LARGURA-1,i,7);
    }
}

void imprimirMatriz()
{
    int i, j;
    for(i=0; i<ALTURA; i++)
    {
        for(j=0; j<LARGURA; j++)
        {
            printf("%d\t",M[i][j]);
            if(j == LARGURA)
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    int cima = 0, baixo = 0, esquerda = 0, direita = 0;
    int x0 = (int)(0.25*LARGURA);
    int y0 = (int)(0.75*ALTURA);
    int i = y0;
    int j = x0;

    system("cls");
    imprimirQuadro();

    while(i<ALTURA-1 && i>=1 && j<LARGURA-1 && j>1 && !M[i][j])
    {

        cima = GetAsyncKeyState(VK_UP);
        baixo = GetAsyncKeyState(VK_DOWN);
        esquerda = GetAsyncKeyState(VK_LEFT);
        direita = GetAsyncKeyState(VK_RIGHT);

        if(cima)
        {
            esquerda = 0;
            direita = 0;
            while(!esquerda && !direita && i<ALTURA-1 && i>=1 && j<LARGURA-1 && j>1 && !M[i][j])
            {
                M[i][j] = 1;
                imprimirCoordenada(j,i,11);
                Sleep(50);
                i--;

                esquerda = GetAsyncKeyState(VK_LEFT);
                direita = GetAsyncKeyState(VK_RIGHT);
            }
        }


        if(baixo)
        {
            esquerda = 0;
            direita = 0;
            while(!esquerda && !direita && i<ALTURA-1 && i>=1 && j<LARGURA-1 && j>1 && !M[i][j])
            {
                M[i][j] = 1;
                imprimirCoordenada(j,i,11);
                Sleep(50);
                i++;

                esquerda = GetAsyncKeyState(VK_LEFT);
                direita = GetAsyncKeyState(VK_RIGHT);
            }
        }

        if(direita)
        {
            cima = 0;
            baixo = 0;
            while(!cima && !baixo && i<ALTURA-1 && i>=1 && j<LARGURA-1 && j>1 && !M[i][j])
            {
                M[i][j] = 1;
                imprimirCoordenada(j,i,11);
                Sleep(50);
                j++;

                cima = GetAsyncKeyState(VK_UP);
                baixo = GetAsyncKeyState(VK_DOWN);
            }
        }

        if(esquerda)
        {
            cima = 0;
            baixo = 0;
            while(!cima && !baixo && i<ALTURA-1 && i>=1 && j<LARGURA-1 && j>1 && !M[i][j])
            {
                M[i][j] = 1;
                imprimirCoordenada(j,i,11);
                Sleep(50);
                j--;

                cima = GetAsyncKeyState(VK_UP);
                baixo = GetAsyncKeyState(VK_DOWN);
            }
        }
    }

    return 0;
}