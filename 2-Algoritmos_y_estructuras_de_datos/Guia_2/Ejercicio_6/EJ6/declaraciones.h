#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int *reservar_memoria(int cnt_elementos);
void reallocar_memoria(int *mult5, int cnt_mult5);
void completar_vector(int *vector, int cnt_elementos);
void imprimir_vector(int *vector, int cnt_elementos);
void ordenar_vector(int *vector, int cnt_elementos);
int multiplo_5(int *vector, int *mult5, int cnt_elementos);


#endif // DECLARACIONES_H_INCLUDED
