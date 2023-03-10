#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

///////////////////////////PILAS////////////////////////////
typedef struct
{
    int A[MAX];
    int top;                       //Apunta al ultimo elemento de la pila.

}PILA;

bool push(PILA *pS, int x);
bool pop(PILA *pS, int *px);
bool isEmpty_pila(PILA *pS);
bool isFull_pila(PILA *pS);
bool peek_pila(PILA *pS, int *px);
void imprimir_pila(PILA pS);


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
bool isEmpty_fila(FILA *pS);
bool isFull_fila(FILA *pS);
bool peek_fila(FILA *pS, int *px);
void imprimir_fila(FILA pS);
void inicializar_fila(FILA *pS);

///////////////////////////LISTAS///////////////////////////

typedef struct
{
    int A[MAX];
    int rear;

}LISTA;

bool insert(int x, int k, LISTA *pS);
bool deletee(int k, LISTA *pS);
bool get(int k, LISTA *pS, int *px);
bool traverse(LISTA *pS);
bool isEmpty_lista(LISTA *pS);
bool isFull_lista(LISTA *pS);

#endif // DECLARACIONES_H_INCLUDED
