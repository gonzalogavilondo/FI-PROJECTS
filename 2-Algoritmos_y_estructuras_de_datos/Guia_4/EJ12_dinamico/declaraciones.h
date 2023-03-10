#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

///////////////////////////PILAS///////////////////////////
typedef struct NODO_1 NODO_1;
typedef struct NODO_1 *PILA;
struct NODO_1
{
    int valor;
    NODO_1 *next;
};

bool isEmpty_pila(PILA *ppS);
bool isFull_pila(PILA *ppS);
bool peek_pila(PILA *ppS, int *px);
bool push(PILA *ppS, int x);
bool pop(PILA *ppS, int *px);
bool imprimir_pila(PILA pS);

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
void inicializar_fila(FILA *pF);
void imprimir_fila(FILA pF);

///////////////////////////FUNCIONES///////////////////////////
void borrar_espacios(char *str);
void cargar_fila_pila(FILA *pF, PILA *pS, int largo, char *frase);
void comparar(FILA *pF, PILA *pS, int largo, int *pXfila, int *pXpila);



#endif // DECLARACIONES_H_INCLUDED
