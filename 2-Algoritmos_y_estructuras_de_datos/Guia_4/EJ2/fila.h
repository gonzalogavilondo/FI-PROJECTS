#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

typedef struct
{
     int A[MAX];
     int size;
     int front;
     int rear;

}FILA;

bool enqueue(FILA *pS, int x);
bool dequeue(FILA *pS, int *px);
bool isEmpty_fila(FILA *pS);
bool isFull_fila(FILA *pS);
bool peek_fila(FILA *pS, int *px);
void imprimir_fila(FILA pS);
void inicializar_fila(FILA *pS);

#endif // FILA_H_INCLUDED
