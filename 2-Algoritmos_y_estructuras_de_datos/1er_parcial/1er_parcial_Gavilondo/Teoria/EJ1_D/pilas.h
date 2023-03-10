#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////PILAS///////////////////////////
typedef struct NODO NODO;
typedef struct NODO *PILA;
struct NODO
{
    int valor;
    NODO *next;
};

bool isEmpty_pila(PILA *ppS);
bool isFull_pila(PILA *ppS);
bool peek_pila(PILA *ppS, int *px);
bool push(PILA *ppS, int x);
bool pop(PILA *ppS, int *px);
bool imprimir_pila(PILA pS);
void cargar_pila(PILA *pS);


#endif // PILAS_H_INCLUDED
