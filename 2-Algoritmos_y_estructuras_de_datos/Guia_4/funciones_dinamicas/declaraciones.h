#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////PILAS///////////////////////////
typedef struct NODO_1 NODO_1;
typedef struct NODO_1 *PILA; //PILA es un tipo de dato del tipo puntero a nodo.
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

typedef struct NODO_2 NODO_2;
struct NODO_2
{
    int valor;
    NODO_2 *next;
};

typedef struct FILA FILA;
struct FILA
{
    NODO_2 *front;
    NODO_2 *rear;
};

bool isEmpty_fila(FILA *pF);
bool isFull_fila(FILA *pF);
bool peek_fila(FILA *pF, int *px);
bool enqueue(FILA *pF,int x);
bool dequeue(FILA *pF, int *px);
bool imprimir_fila(FILA pF);
void inicializar_fila(FILA *pF);

///////////////////////////LISTAS///////////////////////////

#define CNT 10
typedef struct NODO NODO;
struct NODO *lista;
struct NODO
{
    int valor;
    NODO *next;
};
void inicializar_lista(NODO **lista);
void insert(NODO **lista, int pos, int x);
void deletee(NODO **lista, int pos);
bool search(NODO **lista, int x);
void intercambiar(NODO *lista, int pos1, int pos2);
bool traverse(NODO *lista);
int length(NODO *lista);
int get(NODO *lista, int pos);
int mayor(NODO *lista);
int posMayor(NODO *lista);
bool isEmpty(NODO *lista);
bool sort(NODO *lista);
void liberar_memoria(NODO *lista);


#endif // DECLARACIONES_H_INCLUDED
