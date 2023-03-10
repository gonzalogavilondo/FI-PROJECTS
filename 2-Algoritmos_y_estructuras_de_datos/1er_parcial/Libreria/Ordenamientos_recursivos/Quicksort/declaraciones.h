#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define MAX 8

//Quicksort
void quicksort(int *arreglo, int izquierda, int derecha);
int particion(int *arreglo, int izquierda, int derecha);
void intercambiar(int *a, int *b);

//FUNCION IMPRIMIR
void imprimir_datos(int *vector);

#endif // DECLARACIONES_H_INCLUDED
