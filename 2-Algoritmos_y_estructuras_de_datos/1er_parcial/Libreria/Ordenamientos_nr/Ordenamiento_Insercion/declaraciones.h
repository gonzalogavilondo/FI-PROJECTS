#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define CNT 8

int *reservar_memoria(int cnt_elementos);
void completar_vector(int *vector, int cnt_elementos);
void OrdInsercion(int *vector, int cnt_elementos);
void imprimir_vector(int *vector, int cnt_elementos);
int ProcessArray(int *lista, int x, int n);

#endif // DECLARACIONES_H_INCLUDED
