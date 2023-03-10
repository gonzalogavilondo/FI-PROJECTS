#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

///////////////////////////LISTAS///////////////////////////

typedef struct
{
    int A[MAX];
    int rear;

}LISTA;

bool insert(int x, int k, LISTA *pS);
bool delete(int k, LISTA *pS);
bool get(int k, LISTA pS, int *px);
bool traverse(LISTA pS);
bool isEmpty_lista(LISTA pS);
bool isFull_lista(LISTA pS);
void inicializar_lista(LISTA *pS);
void cargar_filas(LISTA *fila1, LISTA *fila2);
void menu(LISTA fila1, LISTA fila2);


#endif // DECLARACIONES_H_INCLUDED
