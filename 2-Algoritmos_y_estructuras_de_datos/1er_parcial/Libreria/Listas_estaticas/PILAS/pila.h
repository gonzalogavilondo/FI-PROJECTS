#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

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


void funcion_peruana(PILA *pS);
#endif // PILA_H_INCLUDED
