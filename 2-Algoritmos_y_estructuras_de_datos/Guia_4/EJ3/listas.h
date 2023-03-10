#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

typedef struct
{
    int A[MAX];
    int rear;

}LISTA;

bool insert(int x, int k, LISTA *pS);
bool delete(int k, LISTA *pS);
bool get(int k, LISTA *pS, int *px);
bool traverse(LISTA *pS);
bool isempty(LISTA *pS);
bool isfull(LISTA *pS);
void imprimir_lista(LISTA *pS);

#endif // LISTAS_H_INCLUDED
