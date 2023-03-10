#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

///////////////////////////FILAS////////////////////////////
typedef struct
{
    int A[MAX];
    int size;
    int front;
    int rear;

}FILA;

bool enqueue(FILA *pS, int x);
bool dequeue(FILA *pS, int *px);
bool isEmpty_fila(FILA pS);
bool isFull_fila(FILA pS);
bool peek_fila(FILA pS, int *px);
void inicializar_fila(FILA *pS);
void imprimir_fila(FILA pS);
void cargar_filas(FILA *fil1, FILA *fil2);
void menu(FILA fil1, FILA fil2);



#endif // DECLARACIONES_H_INCLUDED
