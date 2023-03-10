#ifndef HEADER_OPS_MATRICES_H_INCLUDED
#define HEADER_OPS_MATRICES_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mostrar_matriz (int filas, int columnas, const float nombre_matriz[filas][columnas]);
void suma_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas]);
void resta_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas]);
void mult_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas]);
float mult_escalar (int i, int j, int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas]);
void div_escalar(int filas, int columnas, float matriz[filas][columnas], float escalar);
void transpuesta_matriz(int filas, int columnas, const float matriz_1[filas][columnas], float matriz_2[filas][columnas]);
void completar_matriz (int filas, int columnas, float nombre_matriz[filas][columnas], int nombreMatriz);

#endif // HEADER_OPS_MATRICES_H_INCLUDED




        ////SE PONE CONST PARA QUE NO MODIFIQUE LA MATRIZ, SIEMPRE SE PASA POR REFERENCIA.
