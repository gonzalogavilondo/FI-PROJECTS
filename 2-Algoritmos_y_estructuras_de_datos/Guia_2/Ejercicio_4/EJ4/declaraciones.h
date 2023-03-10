#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(float *vector, float condicion, int cnt_elementos);
void imprimir_vector(float *vector, int cnt_elementos);
void imprimir(int posicion, float condicion);
float *reservar_memoria(int cnt_elementos);
void completar_vector(float *vector, int cnt_elementos);

#endif // DECLARACIONES_H_INCLUDED
