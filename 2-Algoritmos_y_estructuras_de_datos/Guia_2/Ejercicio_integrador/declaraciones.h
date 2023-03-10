#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define FILS 6
#define COLS 6
#define LONGMAX 21
void mapear_matriz(int matriz[FILS][COLS], int vector[LONGMAX]);
void imprimir_vector(int vector[LONGMAX]);
void OrdInsercion(int vector[LONGMAX]);
void busqueda_secuencial(int vector_1[LONGMAX], int vector_2[LONGMAX], int condicion[3], int posicion[3]);
void imprimir(int posicion[3], int condicion[3]);

#endif // DECLARACIONES_H_INCLUDED
