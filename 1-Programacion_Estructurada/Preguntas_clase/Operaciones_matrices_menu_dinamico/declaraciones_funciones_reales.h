#ifndef DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_REALES_H_INCLUDED

void suma_matriz (int filas, int columnas, float **matriz_1, float **matriz_2, float **matriz_3);
void resta_matriz(int filas, int columnas, float **matriz_1, float **matriz_2, float **matriz_3);
void div_escalar(int filas, int columnas, float **matriz_1, float **matriz_2);
void traspuesta_matriz(int filas, int columnas, float **matriz_1, float **matriz_2);
void multiplicar_filas_matriz (int filas, int columnas, float **matriz_1, float **matriz_2);
void multiplicar_matrices (int filas1, int columnas1, int filas2, int columnas2, float **matriz_1, float **matriz_2, float **matriz_3);
float multiplicar_escalar_matrices(int i, int j, int elementos, float **matriz_1, float **matriz_2);
float multiplicar_escalar_matriz (int i, int j, int filas, float **matriz_2);

#endif // DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
