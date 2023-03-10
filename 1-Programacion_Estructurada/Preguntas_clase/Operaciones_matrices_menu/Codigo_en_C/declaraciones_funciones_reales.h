#ifndef DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_REALES_H_INCLUDED

#define FILSMAX 10
#define COLSMAX 10
void suma_matriz (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);
void resta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);
void div_escalar(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX]);
void traspuesta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX]);
void multiplicar_filas_matriz (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX]);
void multiplicar_matrices (int filas1, int columnas1, int filas2, int columnas2, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);
float multiplicar_escalar_matrices(int i, int j, int elementos, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX]);
float multiplicar_escalar_matriz (int i, int j, int filas, const float matriz_2[FILSMAX][COLSMAX]);
//int determinante(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX]);
//void inversa_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);

#endif // DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
