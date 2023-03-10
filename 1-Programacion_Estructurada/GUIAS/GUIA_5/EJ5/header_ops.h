#ifndef HEADER_OPS_H_INCLUDED
#define HEADER_OPS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define FILS 3
#define COLS 5

void imprimir_vector (const float [COLS]);
void completar_vector(float [COLS]);
void completar_matriz(const float [COLS], const float [COLS], const float [COLS], float [FILS][COLS]);
void imprimir_matriz (const float [][COLS]);
float promedio_por_fila (const float [COLS]);
float promedio_total (const float [FILS][COLS]);
float maximo_total (const float [FILS][COLS]);


#endif // HEADER_OPS_H_INCLUDED
