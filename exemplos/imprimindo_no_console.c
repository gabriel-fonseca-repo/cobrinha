#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void imprimir(int x, int y, int cor)
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

int main()
{
    system("cls");

    imprimir(0,0,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    imprimir(0,1,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    imprimir(1,1,FOREGROUND_RED|FOREGROUND_INTENSITY);

    return 0;
}