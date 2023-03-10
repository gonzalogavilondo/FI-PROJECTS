#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define LONGMAX 9

void OrdInsercion(int vector[LONGMAX], int cnt_elementos);
void imprimir(int posicion[7], int condicion[7]);
void busqueda_secuencial(int vector[LONGMAX], int condicion[7], int posicion[7]);
void imprimir_vector(int vector[LONGMAX], int cnt_elementos);

#endif // DECLARACIONES_H_INCLUDED
