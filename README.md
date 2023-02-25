# Cobrinha em C - Aprendizagem de sistemas operacionais.

## Clone do jogo da cobrinha implementado em C utilizando-se da api nativa do windows ```<windows.h>``` e ```<pthread.h>``` com intúito de aprender tecnologias a nível de sistema operacional.

```c
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>

#define ALTURA 25
#define LARGURA 75
#define TAMANHO_INICIAL 10

int M[ALTURA][LARGURA] = {{0}};

void imprimirCoordenada(int x, int y, int cor){}
void imprimirQuadro(){}
void imprimirMatriz(){}
void *handlePlayer2(void *n){}
void *handlePlayer1(void *n){}

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
```