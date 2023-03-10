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
void cargar_pila(PILA *pS);

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
void cargar_fila(FILA *pF);

///////////////////////////LISTAS///////////////////////////

#define CNT 10
typedef struct List list;
typedef struct List
{
    int value;
    list *next;

} list;

void insert(list **lista, int pos, int x);
void deletee(list **lista, int pos);
bool search(list **lista, int x);
void intercambiar(list *lista, int pos1, int pos2);
bool traverse(list *lista);
int length(list *lista);
int get(list *lista, int pos);
int mayor(list *lista);
int posMayor(list *lista);
bool isEmpty(list *lista);
bool sort(list *lista);
void liberar_memoria(list *lista);


#endif // DECLARACIONES_H_INCLUDED
