#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define FILSMAX 4
#define COLSMAX 4
#define LONGMAX 4

void mapear_matriz(float matriz[FILSMAX][COLSMAX], float vector[LONGMAX]);
void imprimir_matriz (float matriz[FILSMAX][COLSMAX]);
void imprimir_vector(float vector[LONGMAX]);

#endif // DECLARACIONES_H_INCLUDED
