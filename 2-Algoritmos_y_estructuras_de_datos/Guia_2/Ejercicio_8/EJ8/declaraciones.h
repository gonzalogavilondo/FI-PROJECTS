#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define FILSMAX 4
#define COLSMAX 4

void completar_matriz (float matriz[FILSMAX][COLSMAX]);
void matriz_diagonal(float matriz[FILSMAX][COLSMAX], float vector[FILSMAX]);
void imprimir_matriz (float matriz[FILSMAX][COLSMAX]);
void imprimir_vector(float vector[FILSMAX]);

#endif // DECLARACIONES_H_INCLUDED
