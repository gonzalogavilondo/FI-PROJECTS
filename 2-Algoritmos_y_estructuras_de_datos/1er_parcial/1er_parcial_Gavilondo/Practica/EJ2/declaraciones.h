#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILS 7
#define COLS 7
#define MAX 21


//PILAS
typedef struct
{
     int A[MAX];
     int top;                       //Apunta al ultimo elemento de la pila.

}PILA;

bool push(PILA *pS, int x);
bool pop(PILA *pS, int *px);
bool isEmpty(PILA *pS);
bool isFull(PILA *pS);
bool peek(PILA *pS, int *px);
void imprimir_pila(PILA pS);
void inicializar_pila(PILA *pS);

//LISTAS
typedef struct
{
    int A[MAX];
    int rear;

}LISTA;

bool insert(int x, int k, LISTA *pS);
bool deletee(int k, LISTA *pS);
bool get(int k, LISTA *pS, int *px);
bool traverse(LISTA *pS);
bool isempty(LISTA *pS);
bool isfull(LISTA *pS);
void inicializar_lista(LISTA *lista);
void imprimir_lista(LISTA *pS);

//FUNCIONES
///Inciso a)
void mapear_matriz(char matriz[FILS][COLS], char vector[MAX]);
void imprimir_matriz (char matriz[FILS][COLS]);
void imprimir_vector_char(char vector[MAX]);
void imprimir_vector_int(int vector[7]);

///Inciso b)
int codificacion(char vector[MAX]);
void comprobar(int codificar);

///Inciso c y d)
void char_a_entero(char vector[MAX], int vectop[7]);
int maximo(int vectop[MAX], int inf, int sup);
int minimo(int vectop[MAX], int inf, int sup);
int busqueda_secuencial(int vectop[], int condicion, int dim);

///Inciso e)
void couting(int vectord[7], int vectop[7], int min, int max);

///Inciso f)
void cargar_lista(int vectop[7], LISTA *lista);
int posmin_lista(LISTA *pS); //Retorna la posicion del nodo con mayor informacion.


#endif // DECLARACIONES_H_INCLUDED
