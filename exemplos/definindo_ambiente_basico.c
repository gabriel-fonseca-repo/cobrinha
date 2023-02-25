#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ALTURA 50
#define LARGURA 150

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
    for(i=0;i<LARGURA;i++)
    {
        imprimirCoordenada(i,0,7);
        imprimirCoordenada(i,ALTURA-1,7);
    }
    for(i=0;i<ALTURA;i++)
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
    system("cls");
    imprimirQuadro();

    int x0 = (int)(0.25*LARGURA);
    int y0 = (int)(0.75*ALTURA);

    int i = y0;
    int j = x0;

    while(j<LARGURA-1 && j>1)
    {
       M[i][j] = 1;
       imprimirCoordenada(j,i,11);
       Sleep(50);
       j++;
    }

    return 0;
}