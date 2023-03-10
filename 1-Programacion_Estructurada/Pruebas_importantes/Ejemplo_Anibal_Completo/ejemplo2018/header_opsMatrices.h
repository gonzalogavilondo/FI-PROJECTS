#ifndef HEADER_OPSMATRICES_H_INCLUDED
#define HEADER_OPSMATRICES_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mostrar_matriz (int filas, int columnas, const float nombre_matriz[filas][columnas]);
void suma_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas]);
void resta_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas]);
void mult_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas]);
float mult_escalar (int i, int j, int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas]);
void div_escalar(int filas, int columnas, const float matriz_1[filas][columnas], float matriz_2[filas][columnas]);
void transpuesta_matriz(int filas, int columnas, const float matriz_1[filas][columnas], float matriz_2[filas][columnas]);
void completar_matriz (int filas, int columnas, float nombre_matriz[filas][columnas], char nombreMatriz);

#endif // HEADER_OPSMATRICES_H_INCLUDED
