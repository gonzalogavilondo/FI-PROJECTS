#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define FILS 3
#define COLS 3

void completar_vector(float vector[COLS], int n);
void imprimir_vector(float vector[COLS]);
void completar_matriz(const float vector1[COLS], const float vector2[COLS], const float vector3[COLS], float matriz[FILS][COLS]);
void imprimir_matriz(const float matriz[FILS][COLS]);




#endif // HEADER_H_INCLUDED
