#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int *reservar_memoria(int cnt_elementos);
void completar_vector(int *vector, int cnt_elementos);
void OrdSeleccion(int *vector, int cnt_elementos);
void imprimir_vector(int *vector, int cnt_elementos);

#endif // DECLARACIONES_H_INCLUDED
