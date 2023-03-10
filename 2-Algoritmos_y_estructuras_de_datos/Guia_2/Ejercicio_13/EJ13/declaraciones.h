#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define FILSMAX 5
#define COLSMAX 5
#define LONGMAX 15

void completar_matriz (float matriz[FILSMAX][COLSMAX]);
void mapear_matriz(float matriz[FILSMAX][COLSMAX], float vector[LONGMAX]);
void imprimir_matriz (float matriz[FILSMAX][COLSMAX]);
void imprimir_vector(float vector[LONGMAX]);
int busqueda_binaria(float vector[LONGMAX], float condicion);
void OrdInsercion(float vector[FILSMAX]);
void imprimir(int posicion, float condicion);


#endif // DECLARACIONES_H_INCLUDED
