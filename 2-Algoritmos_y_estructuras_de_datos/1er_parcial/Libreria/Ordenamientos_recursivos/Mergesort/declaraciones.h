#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#define MAX 8

//Mergesort
void mergesort(int *vector, int low, int high);
void merge(int *vector, int low, int mid, int high);

//Funcion imprimir
void imprimir_datos(int *vector);

#endif // DECLARACIONES_H_INCLUDED
