#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////FILAS///////////////////////////

typedef struct NODO NODO;
struct NODO
{
    int valor;
    NODO *next;
};

typedef struct FILA FILA;
struct FILA
{
    NODO *front;
    NODO *rear;
};

bool isEmpty_fila(FILA *pF);
bool isFull_fila(FILA *pF);
bool peek_fila(FILA *pF, int *px);
bool enqueue(FILA *pF,int x);
bool dequeue(FILA *pF, int *px);
bool imprimir_fila(FILA pF);
void inicializar_fila(FILA *pF);
void cargar_fila(FILA *pF);



#endif // DECLARACIONES_H_INCLUDED
