#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 40

///////////////////////////PILAS////////////////////////////
typedef struct
{
    int A[MAX];
    int top;

}PILA;

bool push(PILA *pS, int x);
bool pop(PILA *pS, int *px);
bool isEmpty_pila(PILA pS);
bool isFull_pila(PILA pS);
bool peek_pila(PILA pS, int *px);
void inicializar_pila(PILA *pS);
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
bool isEmpty_fila(FILA pS);
bool isFull_fila(FILA pS);
bool peek_fila(FILA pS, int *px);
void inicializar_fila(FILA *pS);
void imprimir_fila(FILA pS);

///////////////////////////FUNCIONES///////////////////////////
void borrar_espacios(char *str);
void cargar_fila_pila(FILA *pF, PILA *pS, int largo, char *frase);
void comparar(FILA *pF, PILA *pS, int largo, int *pXfila, int *pXpila);


#endif // DECLARACIONES_H_INCLUDED
